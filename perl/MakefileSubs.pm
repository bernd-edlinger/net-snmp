package MakefileSubs;

use strict;
use warnings;
use Config;
use Cwd 'abs_path';
use File::Basename;
use Getopt::Long;
use Exporter;
use vars qw(@ISA @EXPORT_OK);

our $VERSION = 1.00;
our @ISA     = qw(Exporter);
our @EXPORT  = qw(NetSNMPGetOpts find_files Check_Version floatize_version);
our $basedir;

sub NetSNMPGetOpts {
    my %ret;
    my $rootpath = shift;
    $rootpath = "../" if (!$rootpath);
    $rootpath .= '/' if ($rootpath !~ /\/$/);

    if ($Config{'osname'} eq 'MSWin32' && !defined($ENV{'OSTYPE'})) {
      $basedir = abs_path($0);
      while (1) {
          my $basename = basename($basedir);
          last if (length($basename) <= 2);
          $basedir = dirname($basedir);
          last if ($basename eq "perl");
      }
      print "Net-SNMP base directory: $basedir\n";
      if ($basedir =~ / /) {
        die "\nA space has been detected in the base directory.  This is not " .
            "supported\nPlease rename the folder and try again.\n\n";
      }
    }

    if ($ENV{'NET-SNMP-CONFIG'} && $ENV{'NET-SNMP-IN-SOURCE'}) {
	# have env vars, pull from there
	$ret{'nsconfig'} = $ENV{'NET-SNMP-CONFIG'};
	$ret{'insource'} = $ENV{'NET-SNMP-IN-SOURCE'};
    } else {
	# don't have env vars, pull from command line and put there
	GetOptions("NET-SNMP-CONFIG=s" => \$ret{'nsconfig'},
	           "NET-SNMP-IN-SOURCE=s" => \$ret{'insource'});

	my $use_default_nsconfig;

	if ($ret{'insource'}) {
	    if (lc($ret{'insource'}) eq "true" && !defined($ret{'nsconfig'})) {
		$use_default_nsconfig = 1;
	    }
	}

	if ($use_default_nsconfig) {
	    $ret{'nsconfig'}="sh ${rootpath}../net-snmp-config";
	} elsif (!defined($ret{'nsconfig'})) {
	    $ret{'nsconfig'}="net-snmp-config";
	}

	$ENV{'NET-SNMP-CONFIG'}    = $ret{'nsconfig'};
	$ENV{'NET-SNMP-IN-SOURCE'} = $ret{'insource'};
    }
    
    $ret{'rootpath'} = $rootpath;
    $ret{'debug'} = 'false';

    \%ret;
}

sub find_files {
    my($f,$d) = @_;
    my ($dir,$found,$file);
    for $dir (@$d){
	$found = 0;
	for $file (@$f) {
	    $found++ if -f "$dir/$file";
	}
	if ($found == @$f) {
	    return $dir;
	}
    }
}


sub Check_Version
{
  my $lib_version = shift;

  if ($Config{'osname'} ne 'MSWin32') {
    my $foundversion = 0;
    return if ($ENV{'NETSNMP_DONT_CHECK_VERSION'});
    open(I,"<Makefile");
    while (<I>) {
	if (/^VERSION = (.*)/) {
	    my $perlver = $1;
	    my $srcver = $lib_version;
	    chomp($srcver);
	    my $srcfloat = floatize_version($srcver);
	    $perlver =~ s/pre/0./;
	    # we allow for perl/CPAN-only revisions beyond the default
	    # version formatting of net-snmp itself.
	    $perlver =~ s/(\.\d{5}).*/$1/;
	    $perlver =~ s/0*$//;
	    if ($srcfloat ne $perlver) {
		if (!$foundversion) {
		    print STDERR "ERROR:
Net-SNMP installed version: $srcver => $srcfloat
Perl Module Version:        $perlver

These versions must match for perfect support of the module.  It is possible
that different versions may work together, but it is strongly recommended
that you make these two versions identical.  You can get the Net-SNMP
source code and the associated perl modules directly from

   http://www.net-snmp.org/

If you want to continue anyway please set the NETSNMP_DONT_CHECK_VERSION
environmental variable to 1 and re-run the Makefile.PL script.\n";
		    exit(1);
		}
	    }
	    $foundversion = 1;
	    last;
	}
    }
    close(I);
    die "ERROR: Couldn't find version number of this module\n"
      if (!$foundversion);
  }
}

sub floatize_version {
    my ($major, $minor, $patch, $opps) = ($_[0] =~ /^(\d+)\.(\d+)\.?(\d*)\.?(\d*)/);
    if (!$patch) {
        $patch = 0;
    }
    if (!$opps) {
        $opps = 0;
    }
    return $major + $minor/100 + $patch/10000 + $opps/100000;
}

1;
