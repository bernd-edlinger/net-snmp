/*
 * Note: this file originally auto-generated by mib2c using
 *       version : 1.17 $ of : mfd-top.m2c,v $
 *
 * $Id$
 */
#ifndef IFTABLE_H
#define IFTABLE_H

#ifdef __cplusplus
extern          "C" {
#endif


/** @defgroup misc misc: Miscelaneous routines
 *
 * @{
 */
#include <net-snmp/library/asn1.h>
#include <net-snmp/data_access/interface.h>

    /*
     * other required module components 
     */
    config_require(if-mib/data_access/interface);
    config_require(if-mib/ifTable/ifTable_interface);
    config_require(if-mib/ifTable/ifTable_data_access);

    /*
     * OID, column number and enum definions for  
     */
#include "ifTable_constants.h"

    /*
     *********************************************************************
     * function declarations
     */
    void            init_ifTable(void);

    /*
     *********************************************************************
     * Table declarations
     */
/**********************************************************************
 **********************************************************************
 ***
 *** Table ifTable
 ***
 **********************************************************************
 **********************************************************************/
    /*
     * ifTable is subid 2 of interfaces.
     * It's status is Mandatory.
     * OID: .1.3.6.1.2.1.2.2, length: 8
     */
    /*
     *********************************************************************
     * When you register your mib, you get to provide a generic
     * pointer that will be passed back to you for most of the
     * functions calls.
     */
    typedef netsnmp_data_list *ifTable_registration_ptr;

/**********************************************************************/
    /*
     * data context
     */
    typedef netsnmp_interface_entry ifTable_data;


    /*
     *********************************************************************
     * undo context
     * We're just going to use the same data structure for our
     * undo_context. If you want to do something more efficent,
     * define your typedef here.
     */
    typedef ifTable_data ifTable_undo_data;

    /*
     * This structure is used to represent the index for a table.
     */
    typedef struct ifTable_mib_index_s {

        /** ifIndex(1)/INTEGER/ASN_INTEGER/long(long)//l/A/w/e/r/d/h */
        long            ifIndex;


    } ifTable_mib_index;


    /*
     *********************************************************************
     * Row request context
     * When your functions are called, you will be passed a
     * ifTable_rowreq_ctx pointer.
     */
    typedef struct ifTable_rowreq_ctx_s {

    /** this must be first for container compare to work */
        netsnmp_index   oid_idx;
        oid             oid_tmp[MAX_OID_LEN];   /* xxx-rks: shrink this */

        ifTable_mib_index tbl_idx;

        ifTable_data   *data;
        ifTable_undo_data *undo;

    /** implementor's context pointer provided during registration */
        ifTable_registration_ptr ifTable_reg;

        /*
         * TODO:
         * add any other useful data
         *       (e.g. flags for when a column has been set)
         */

        /*
         * storage for future expansion
         */
        netsnmp_data_list *ifTable_data_list;

    } ifTable_rowreq_ctx;

    typedef struct ifTable_ref_rowreq_ctx_s {
        ifTable_rowreq_ctx *rowreq_ctx;
    } ifTable_ref_rowreq_ctx;

    /*
     *********************************************************************
     * function prototypes
     */
    int             ifTable_pre_request(ifTable_registration_ptr
                                        user_context);
    int             ifTable_post_request(ifTable_registration_ptr
                                         user_context);

    ifTable_data   *ifTable_allocate_data(void);
    void            ifTable_release_data(ifTable_data * data);

    int             ifTable_check_dependencies(ifTable_rowreq_ctx *
                                               rowreq_ctx);
    int             ifTable_commit(ifTable_rowreq_ctx * rowreq_ctx);

    extern oid      ifTable_oid[];
    extern int      ifTable_oid_size;


#include "ifTable_interface.h"
#include "ifTable_data_access.h"
    /*
     *********************************************************************
     * GET function declarations
     */

    /*
     *********************************************************************
     * GET Table declarations
     */
/**********************************************************************
 **********************************************************************
 ***
 *** Table ifTable
 ***
 **********************************************************************
 **********************************************************************/
    /*
     * ifTable is subid 2 of interfaces.
     * It's status is Mandatory.
     * OID: .1.3.6.1.2.1.2.2, length: 8
     */
    /*
     * indexes
     */

    int             ifDescr_get(ifTable_rowreq_ctx * rowreq_ctx,
                                char **ifDescr_ptr_ptr,
                                size_t * ifDescr_ptr_len_ptr);
    int             ifType_get(ifTable_rowreq_ctx * rowreq_ctx,
                               u_long * ifType_ptr);
    int             ifMtu_get(ifTable_rowreq_ctx * rowreq_ctx,
                              long *ifMtu_ptr);
    int             ifSpeed_get(ifTable_rowreq_ctx * rowreq_ctx,
                                u_long * ifSpeed_ptr);
    int             ifPhysAddress_get(ifTable_rowreq_ctx * rowreq_ctx,
                                      char **ifPhysAddress_ptr_ptr,
                                      size_t * ifPhysAddress_ptr_len_ptr);
    int             ifAdminStatus_get(ifTable_rowreq_ctx * rowreq_ctx,
                                      u_long * ifAdminStatus_ptr);
    int             ifOperStatus_get(ifTable_rowreq_ctx * rowreq_ctx,
                                     u_long * ifOperStatus_ptr);
    int             ifLastChange_get(ifTable_rowreq_ctx * rowreq_ctx,
                                     u_long * ifLastChange_ptr);
    int             ifInOctets_get(ifTable_rowreq_ctx * rowreq_ctx,
                                   u_long * ifInOctets_ptr);
    int             ifInUcastPkts_get(ifTable_rowreq_ctx * rowreq_ctx,
                                      u_long * ifInUcastPkts_ptr);
    int             ifInNUcastPkts_get(ifTable_rowreq_ctx * rowreq_ctx,
                                       u_long * ifInNUcastPkts_ptr);
    int             ifInDiscards_get(ifTable_rowreq_ctx * rowreq_ctx,
                                     u_long * ifInDiscards_ptr);
    int             ifInErrors_get(ifTable_rowreq_ctx * rowreq_ctx,
                                   u_long * ifInErrors_ptr);
    int             ifInUnknownProtos_get(ifTable_rowreq_ctx * rowreq_ctx,
                                          u_long * ifInUnknownProtos_ptr);
    int             ifOutOctets_get(ifTable_rowreq_ctx * rowreq_ctx,
                                    u_long * ifOutOctets_ptr);
    int             ifOutUcastPkts_get(ifTable_rowreq_ctx * rowreq_ctx,
                                       u_long * ifOutUcastPkts_ptr);
    int             ifOutNUcastPkts_get(ifTable_rowreq_ctx * rowreq_ctx,
                                        u_long * ifOutNUcastPkts_ptr);
    int             ifOutDiscards_get(ifTable_rowreq_ctx * rowreq_ctx,
                                      u_long * ifOutDiscards_ptr);
    int             ifOutErrors_get(ifTable_rowreq_ctx * rowreq_ctx,
                                    u_long * ifOutErrors_ptr);
    int             ifOutQLen_get(ifTable_rowreq_ctx * rowreq_ctx,
                                  u_long * ifOutQLen_ptr);
    int             ifSpecific_get(ifTable_rowreq_ctx * rowreq_ctx,
                                   oid ** ifSpecific_ptr_ptr,
                                   size_t * ifSpecific_ptr_len_ptr);


    int             ifTable_indexes_set_tbl_idx(ifTable_mib_index *
                                                tbl_idx, long ifIndex);
    int             ifTable_indexes_set(ifTable_rowreq_ctx * rowreq_ctx,
                                        long ifIndex);



    /*
     *********************************************************************
     * SET function declarations
     */

    /*
     *********************************************************************
     * SET Table declarations
     */
/**********************************************************************
 **********************************************************************
 ***
 *** Table ifTable
 ***
 **********************************************************************
 **********************************************************************/
    /*
     * ifTable is subid 2 of interfaces.
     * It's status is Mandatory.
     * OID: .1.3.6.1.2.1.2.2, length: 8
     */
    int             ifIndex_check_index(ifTable_rowreq_ctx * rowreq_ctx);       /* internal */


    int             ifTable_undo_setup(ifTable_rowreq_ctx * rowreq_ctx);
    int             ifTable_commit(ifTable_rowreq_ctx * rowreq_ctx);


    int             ifDescr_check_value(ifTable_rowreq_ctx * rowreq_ctx,
                                        char *ifDescr_ptr,
                                        size_t ifDescr_ptr_len);
    int             ifDescr_undo_setup(ifTable_rowreq_ctx * rowreq_ctx);
    int             ifDescr_set(ifTable_rowreq_ctx * rowreq_ctx,
                                char *ifDescr_ptr, size_t ifDescr_ptr_len);
    int             ifDescr_undo(ifTable_rowreq_ctx * rowreq_ctx);

    int             ifType_check_value(ifTable_rowreq_ctx * rowreq_ctx,
                                       u_long ifType);
    int             ifType_undo_setup(ifTable_rowreq_ctx * rowreq_ctx);
    int             ifType_set(ifTable_rowreq_ctx * rowreq_ctx,
                               u_long ifType);
    int             ifType_undo(ifTable_rowreq_ctx * rowreq_ctx);

    int             ifMtu_check_value(ifTable_rowreq_ctx * rowreq_ctx,
                                      long ifMtu);
    int             ifMtu_undo_setup(ifTable_rowreq_ctx * rowreq_ctx);
    int             ifMtu_set(ifTable_rowreq_ctx * rowreq_ctx, long ifMtu);
    int             ifMtu_undo(ifTable_rowreq_ctx * rowreq_ctx);

    int             ifSpeed_check_value(ifTable_rowreq_ctx * rowreq_ctx,
                                        u_long ifSpeed);
    int             ifSpeed_undo_setup(ifTable_rowreq_ctx * rowreq_ctx);
    int             ifSpeed_set(ifTable_rowreq_ctx * rowreq_ctx,
                                u_long ifSpeed);
    int             ifSpeed_undo(ifTable_rowreq_ctx * rowreq_ctx);

    int             ifPhysAddress_check_value(ifTable_rowreq_ctx *
                                              rowreq_ctx,
                                              char *ifPhysAddress_ptr,
                                              size_t
                                              ifPhysAddress_ptr_len);
    int             ifPhysAddress_undo_setup(ifTable_rowreq_ctx *
                                             rowreq_ctx);
    int             ifPhysAddress_set(ifTable_rowreq_ctx * rowreq_ctx,
                                      char *ifPhysAddress_ptr,
                                      size_t ifPhysAddress_ptr_len);
    int             ifPhysAddress_undo(ifTable_rowreq_ctx * rowreq_ctx);

    int             ifAdminStatus_check_value(ifTable_rowreq_ctx *
                                              rowreq_ctx,
                                              u_long ifAdminStatus);
    int             ifAdminStatus_undo_setup(ifTable_rowreq_ctx *
                                             rowreq_ctx);
    int             ifAdminStatus_set(ifTable_rowreq_ctx * rowreq_ctx,
                                      u_long ifAdminStatus);
    int             ifAdminStatus_undo(ifTable_rowreq_ctx * rowreq_ctx);

    int             ifOperStatus_check_value(ifTable_rowreq_ctx *
                                             rowreq_ctx,
                                             u_long ifOperStatus);
    int             ifOperStatus_undo_setup(ifTable_rowreq_ctx *
                                            rowreq_ctx);
    int             ifOperStatus_set(ifTable_rowreq_ctx * rowreq_ctx,
                                     u_long ifOperStatus);
    int             ifOperStatus_undo(ifTable_rowreq_ctx * rowreq_ctx);

    int             ifLastChange_check_value(ifTable_rowreq_ctx *
                                             rowreq_ctx,
                                             u_long ifLastChange);
    int             ifLastChange_undo_setup(ifTable_rowreq_ctx *
                                            rowreq_ctx);
    int             ifLastChange_set(ifTable_rowreq_ctx * rowreq_ctx,
                                     u_long ifLastChange);
    int             ifLastChange_undo(ifTable_rowreq_ctx * rowreq_ctx);

    int             ifInOctets_check_value(ifTable_rowreq_ctx * rowreq_ctx,
                                           u_long ifInOctets);
    int             ifInOctets_undo_setup(ifTable_rowreq_ctx * rowreq_ctx);
    int             ifInOctets_set(ifTable_rowreq_ctx * rowreq_ctx,
                                   u_long ifInOctets);
    int             ifInOctets_undo(ifTable_rowreq_ctx * rowreq_ctx);

    int             ifInUcastPkts_check_value(ifTable_rowreq_ctx *
                                              rowreq_ctx,
                                              u_long ifInUcastPkts);
    int             ifInUcastPkts_undo_setup(ifTable_rowreq_ctx *
                                             rowreq_ctx);
    int             ifInUcastPkts_set(ifTable_rowreq_ctx * rowreq_ctx,
                                      u_long ifInUcastPkts);
    int             ifInUcastPkts_undo(ifTable_rowreq_ctx * rowreq_ctx);

    int             ifInNUcastPkts_check_value(ifTable_rowreq_ctx *
                                               rowreq_ctx,
                                               u_long ifInNUcastPkts);
    int             ifInNUcastPkts_undo_setup(ifTable_rowreq_ctx *
                                              rowreq_ctx);
    int             ifInNUcastPkts_set(ifTable_rowreq_ctx * rowreq_ctx,
                                       u_long ifInNUcastPkts);
    int             ifInNUcastPkts_undo(ifTable_rowreq_ctx * rowreq_ctx);

    int             ifInDiscards_check_value(ifTable_rowreq_ctx *
                                             rowreq_ctx,
                                             u_long ifInDiscards);
    int             ifInDiscards_undo_setup(ifTable_rowreq_ctx *
                                            rowreq_ctx);
    int             ifInDiscards_set(ifTable_rowreq_ctx * rowreq_ctx,
                                     u_long ifInDiscards);
    int             ifInDiscards_undo(ifTable_rowreq_ctx * rowreq_ctx);

    int             ifInErrors_check_value(ifTable_rowreq_ctx * rowreq_ctx,
                                           u_long ifInErrors);
    int             ifInErrors_undo_setup(ifTable_rowreq_ctx * rowreq_ctx);
    int             ifInErrors_set(ifTable_rowreq_ctx * rowreq_ctx,
                                   u_long ifInErrors);
    int             ifInErrors_undo(ifTable_rowreq_ctx * rowreq_ctx);

    int             ifInUnknownProtos_check_value(ifTable_rowreq_ctx *
                                                  rowreq_ctx,
                                                  u_long
                                                  ifInUnknownProtos);
    int             ifInUnknownProtos_undo_setup(ifTable_rowreq_ctx *
                                                 rowreq_ctx);
    int             ifInUnknownProtos_set(ifTable_rowreq_ctx * rowreq_ctx,
                                          u_long ifInUnknownProtos);
    int             ifInUnknownProtos_undo(ifTable_rowreq_ctx *
                                           rowreq_ctx);

    int             ifOutOctets_check_value(ifTable_rowreq_ctx *
                                            rowreq_ctx,
                                            u_long ifOutOctets);
    int             ifOutOctets_undo_setup(ifTable_rowreq_ctx *
                                           rowreq_ctx);
    int             ifOutOctets_set(ifTable_rowreq_ctx * rowreq_ctx,
                                    u_long ifOutOctets);
    int             ifOutOctets_undo(ifTable_rowreq_ctx * rowreq_ctx);

    int             ifOutUcastPkts_check_value(ifTable_rowreq_ctx *
                                               rowreq_ctx,
                                               u_long ifOutUcastPkts);
    int             ifOutUcastPkts_undo_setup(ifTable_rowreq_ctx *
                                              rowreq_ctx);
    int             ifOutUcastPkts_set(ifTable_rowreq_ctx * rowreq_ctx,
                                       u_long ifOutUcastPkts);
    int             ifOutUcastPkts_undo(ifTable_rowreq_ctx * rowreq_ctx);

    int             ifOutNUcastPkts_check_value(ifTable_rowreq_ctx *
                                                rowreq_ctx,
                                                u_long ifOutNUcastPkts);
    int             ifOutNUcastPkts_undo_setup(ifTable_rowreq_ctx *
                                               rowreq_ctx);
    int             ifOutNUcastPkts_set(ifTable_rowreq_ctx * rowreq_ctx,
                                        u_long ifOutNUcastPkts);
    int             ifOutNUcastPkts_undo(ifTable_rowreq_ctx * rowreq_ctx);

    int             ifOutDiscards_check_value(ifTable_rowreq_ctx *
                                              rowreq_ctx,
                                              u_long ifOutDiscards);
    int             ifOutDiscards_undo_setup(ifTable_rowreq_ctx *
                                             rowreq_ctx);
    int             ifOutDiscards_set(ifTable_rowreq_ctx * rowreq_ctx,
                                      u_long ifOutDiscards);
    int             ifOutDiscards_undo(ifTable_rowreq_ctx * rowreq_ctx);

    int             ifOutErrors_check_value(ifTable_rowreq_ctx *
                                            rowreq_ctx,
                                            u_long ifOutErrors);
    int             ifOutErrors_undo_setup(ifTable_rowreq_ctx *
                                           rowreq_ctx);
    int             ifOutErrors_set(ifTable_rowreq_ctx * rowreq_ctx,
                                    u_long ifOutErrors);
    int             ifOutErrors_undo(ifTable_rowreq_ctx * rowreq_ctx);

    int             ifOutQLen_check_value(ifTable_rowreq_ctx * rowreq_ctx,
                                          u_long ifOutQLen);
    int             ifOutQLen_undo_setup(ifTable_rowreq_ctx * rowreq_ctx);
    int             ifOutQLen_set(ifTable_rowreq_ctx * rowreq_ctx,
                                  u_long ifOutQLen);
    int             ifOutQLen_undo(ifTable_rowreq_ctx * rowreq_ctx);

    int             ifSpecific_check_value(ifTable_rowreq_ctx * rowreq_ctx,
                                           oid * ifSpecific_ptr,
                                           size_t ifSpecific_ptr_len);
    int             ifSpecific_undo_setup(ifTable_rowreq_ctx * rowreq_ctx);
    int             ifSpecific_set(ifTable_rowreq_ctx * rowreq_ctx,
                                   oid * ifSpecific_ptr,
                                   size_t ifSpecific_ptr_len);
    int             ifSpecific_undo(ifTable_rowreq_ctx * rowreq_ctx);


    int             ifTable_check_dependencies(ifTable_rowreq_ctx * ctx);



#ifndef MFD_SUCCESS
#define MFD_SUCCESS              SNMP_ERR_NOERROR
#define MFD_SKIP                 SNMP_NOSUCHINSTANCE
#define MFD_ERROR                SNMP_ERR_GENERR
#define MFD_RESOURCE_UNAVAILABLE SNMP_ERR_RESOURCEUNAVAILABLE
#define MFD_INCONSISTENT_VALUE   SNMP_ERR_INCONSISTENTVALUE
#define MFD_BAD_VALUE            SNMP_ERR_BADVALUE
#define MFD_END_OF_DATA          SNMP_ENDOFMIBVIEW
#endif

#ifdef __cplusplus
};
#endif

#endif                          /* IFTABLE_H */
