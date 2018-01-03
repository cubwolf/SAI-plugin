/*
 *  Copyright (C) 2016. Marvell International Ltd. ALL RIGHTS RESERVED.
 *
 *    Licensed under the Apache License, Version 2.0 (the "License"); you may
 *    not use this file except in compliance with the License. You may obtain
 *    a copy of the License at http://www.apache.org/licenses/LICENSE-2.0
 *
 *    THIS CODE IS PROVIDED ON AN  *AS IS* BASIS, WITHOUT WARRANTIES OR
 *    CONDITIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED, INCLUDING WITHOUT
 *    LIMITATION ANY IMPLIED WARRANTIES OR CONDITIONS OF TITLE, FITNESS
 *    FOR A PARTICULAR PURPOSE, MERCHANTABLITY OR NON-INFRINGEMENT.
 *
 *    See the Apache Version 2.0 License for specific language governing
 *    permissions and limitations under the License.
 *
 */

#include "sai.h"
#include "mrvl_sai.h"
#include "assert.h"

#undef  __MODULE__
#define __MODULE__ SAI_PORT

#define SAI_PORT_SPEED_10M        10
#define SAI_PORT_SPEED_100M      100
#define SAI_PORT_SPEED_1G       1000
#define SAI_PORT_SPEED_2_5G     2500
#define SAI_PORT_SPEED_10G     10000
#define SAI_PORT_SPEED_20G     20000
#define SAI_PORT_SPEED_25G     25000
#define SAI_PORT_SPEED_40G     40000
#define SAI_PORT_SPEED_100G   100000
#define SAI_PORT_SPEED_1T    1000000

sai_status_t mrvl_port_state_get(_In_ const sai_object_key_t   *key,
                                 _Inout_ sai_attribute_value_t *value,
                                 _In_ uint32_t                  attr_index,
                                 _Inout_ vendor_cache_t        *cache,
                                 void                          *arg);

sai_status_t mrvl_port_hw_lane_get(_In_ const sai_object_key_t   *key,
                                 _Inout_ sai_attribute_value_t *value,
                                 _In_ uint32_t                  attr_index,
                                 _Inout_ vendor_cache_t        *cache,
                                 void                          *arg);

sai_status_t mrvl_port_state_set(_In_ const sai_object_key_t *key,
                                 _In_ const sai_attribute_value_t *value,
                                 void *arg);

sai_status_t mrvl_port_supported_speed_get(_In_ const sai_object_key_t   *key,
                                           _Inout_ sai_attribute_value_t *value,
                                           _In_ uint32_t                  attr_index,
                                           _Inout_ vendor_cache_t        *cache,
                                           void                          *arg);

sai_status_t mrvl_port_speed_get(_In_ const sai_object_key_t   *key,
                                 _Inout_ sai_attribute_value_t *value,
                                 _In_ uint32_t                  attr_index,
                                 _Inout_ vendor_cache_t        *cache,
                                 void                          *arg);

sai_status_t mrvl_port_speed_set(_In_ const sai_object_key_t      *key, 
                                 _In_ const sai_attribute_value_t *value, 
                                 void                             *arg);

sai_status_t mrvl_port_fc_get(_In_ const sai_object_key_t   *key,
                              _Inout_ sai_attribute_value_t *value,
                              _In_ uint32_t                  attr_index,
                              _Inout_ vendor_cache_t        *cache,
                              void                          *arg);

sai_status_t mrvl_port_fc_set(_In_ const sai_object_key_t      *key, 
                              _In_ const sai_attribute_value_t *value, 
                              void                             *arg);

sai_status_t mrvl_port_fdb_learning_get(_In_ const sai_object_key_t   *key,
                                        _Inout_ sai_attribute_value_t *value,
                                        _In_ uint32_t                  attr_index,
                                        _Inout_ vendor_cache_t        *cache,
                                        void                          *arg);

sai_status_t mrvl_port_fdb_learning_set(_In_ const sai_object_key_t      *key,
                                        _In_ const sai_attribute_value_t *value,
                                        void                             *arg);

sai_status_t mrvl_port_default_vlan_get(_In_ const sai_object_key_t   *key,
                                        _Inout_ sai_attribute_value_t *value,
                                        _In_ uint32_t                  attr_index,
                                        _Inout_ vendor_cache_t        *cache,
                                        void                          *arg);

sai_status_t mrvl_port_default_vlan_prio_get(_In_ const sai_object_key_t   *key,
                                             _Inout_ sai_attribute_value_t *value,
                                             _In_ uint32_t                  attr_index,
                                             _Inout_ vendor_cache_t        *cache,
                                             void                          *arg);

sai_status_t mrvl_port_default_vlan_set(_In_ const sai_object_key_t      *key,
                                        _In_ const sai_attribute_value_t *value,
                                        void                             *arg);

sai_status_t mrvl_port_default_vlan_prio_set(_In_ const sai_object_key_t      *key,
                                             _In_ const sai_attribute_value_t *value,
                                             void                             *arg);

sai_status_t mrvl_port_acl_binding_set(_In_ const sai_object_key_t      *key,
                                       _In_ const sai_attribute_value_t *value,
                                       void                             *arg);

sai_status_t mrvl_port_acl_binding_get(_In_ const sai_object_key_t   *key,
                                       _Inout_ sai_attribute_value_t *value,
                                       _In_ uint32_t                  attr_index,
                                       _Inout_ vendor_cache_t        *cache,
                                       void                          *arg);

sai_status_t mrvl_port_qos_num_queues_get(_In_ const sai_object_key_t   *key,
                                        _Inout_ sai_attribute_value_t *value,
                                        _In_ uint32_t                  attr_index,
                                        _Inout_ vendor_cache_t        *cache,
                                        void                          *arg);

sai_status_t mrvl_port_qos_queue_list_get(_In_ const sai_object_key_t   *key,
                                        _Inout_ sai_attribute_value_t *value,
                                        _In_ uint32_t                  attr_index,
                                        _Inout_ vendor_cache_t        *cache,
                                        void                          *arg);

sai_status_t mrvl_port_number_of_priority_groups_get(_In_ const sai_object_key_t   *key,
                                                            _Inout_ sai_attribute_value_t *value,
                                                            _In_ uint32_t                  attr_index,
                                                            _Inout_ vendor_cache_t        *cache,
                                                            void                          *arg);

sai_status_t mrvl_port_priority_group_list_get(_In_ const sai_object_key_t   *key,
                                                      _Inout_ sai_attribute_value_t *value,
                                                      _In_ uint32_t                  attr_index,
                                                      _Inout_ vendor_cache_t        *cache,
                                                      void                          *arg);

static sai_status_t mrvl_port_sched_groups_num_get(_In_ const sai_object_key_t   *key,
                                                   _Inout_ sai_attribute_value_t *value,
                                                   _In_ uint32_t                  attr_index,
                                                   _Inout_ vendor_cache_t        *cache,
                                                   void                          *arg);

static sai_status_t mrvl_port_sched_groups_list_get(_In_ const sai_object_key_t   *key,
                                                    _Inout_ sai_attribute_value_t *value,
                                                    _In_ uint32_t                  attr_index,
                                                    _Inout_ vendor_cache_t        *cache,
                                                    void                          *arg);

static sai_status_t mrvl_port_tc_get(_In_ const sai_object_id_t port, _Out_ uint8_t *tc);

static sai_status_t mrvl_port_ingress_filter_set(_In_ const sai_object_key_t      *key,
                                                 _In_ const sai_attribute_value_t *value,
                                                 void                             *arg);
static sai_status_t mrvl_port_drop_tags_set(_In_ const sai_object_key_t      *key,
                                            _In_ const sai_attribute_value_t *value,
                                            void                             *arg);
static sai_status_t mrvl_port_internal_loopback_set(_In_ const sai_object_key_t      *key,
                                                    _In_ const sai_attribute_value_t *value,
                                                    void                             *arg);
static sai_status_t mrvl_port_mtu_set(_In_ const sai_object_key_t      *key,
                                      _In_ const sai_attribute_value_t *value,
                                      void                             *arg);

static sai_status_t mrvl_port_fec_set(_In_ const sai_object_key_t      *key,
                                      _In_ const sai_attribute_value_t *value,
                                      void                             *arg);
static sai_status_t mrvl_port_auto_negotiation_set(_In_ const sai_object_key_t      *key,
                                                   _In_ const sai_attribute_value_t *value,
                                                   void                             *arg);
static sai_status_t mrvl_port_wred_set(_In_ const sai_object_key_t      *key,
                                       _In_ const sai_attribute_value_t *value,
                                       void                             *arg);
static sai_status_t mrvl_port_type_get(_In_ const sai_object_key_t   *key,
                                       _Inout_ sai_attribute_value_t *value,
                                       _In_ uint32_t                  attr_index,
                                       _Inout_ vendor_cache_t        *cache,
                                       void                          *arg);

static sai_status_t mrvl_port_supported_breakout_get(_In_ const sai_object_key_t   *key,
                                                     _Inout_ sai_attribute_value_t *value,
                                                     _In_ uint32_t                  attr_index,
                                                     _Inout_ vendor_cache_t        *cache,
                                                     void                          *arg);
static sai_status_t mrvl_port_current_breakout_get(_In_ const sai_object_key_t   *key,
                                                   _Inout_ sai_attribute_value_t *value,
                                                   _In_ uint32_t                  attr_index,
                                                   _Inout_ vendor_cache_t        *cache,
                                                   void                          *arg);

static sai_status_t mrvl_port_supported_fec_mode_get(_In_ const sai_object_key_t   *key,
                                                     _Inout_ sai_attribute_value_t *value,
                                                     _In_ uint32_t                  attr_index,
                                                     _Inout_ vendor_cache_t        *cache,
                                                     void                          *arg);

static sai_status_t mrvl_port_fec_get(_In_ const sai_object_key_t   *key,
                                      _Inout_ sai_attribute_value_t *value,
                                      _In_ uint32_t                  attr_index,
                                      _Inout_ vendor_cache_t        *cache,
                                      void                          *arg);
static sai_status_t mrvl_port_duplex_get(_In_ const sai_object_key_t   *key,
                                         _Inout_ sai_attribute_value_t *value,
                                         _In_ uint32_t                  attr_index,
                                         _Inout_ vendor_cache_t        *cache,
                                         void                          *arg);
static sai_status_t mrvl_port_auto_negotiation_get(_In_ const sai_object_key_t   *key,
                                                   _Inout_ sai_attribute_value_t *value,
                                                   _In_ uint32_t                  attr_index,
                                                   _Inout_ vendor_cache_t        *cache,
                                                   void                          *arg);

static sai_status_t mrvl_port_ingress_filter_get(_In_ const sai_object_key_t   *key,
                                                 _Inout_ sai_attribute_value_t *value,
                                                 _In_ uint32_t                  attr_index,
                                                 _Inout_ vendor_cache_t        *cache,
                                                 void                          *arg);
static sai_status_t mrvl_port_drop_tags_get(_In_ const sai_object_key_t   *key,
                                            _Inout_ sai_attribute_value_t *value,
                                            _In_ uint32_t                  attr_index,
                                            _Inout_ vendor_cache_t        *cache,
                                            void                          *arg);
static sai_status_t mrvl_port_internal_loopback_get(_In_ const sai_object_key_t   *key,
                                                    _Inout_ sai_attribute_value_t *value,
                                                    _In_ uint32_t                  attr_index,
                                                    _Inout_ vendor_cache_t        *cache,
                                                    void                          *arg);
static sai_status_t mrvl_port_mtu_get(_In_ const sai_object_key_t   *key,
                                      _Inout_ sai_attribute_value_t *value,
                                      _In_ uint32_t                  attr_index,
                                      _Inout_ vendor_cache_t        *cache,
                                      void                          *arg);

static sai_status_t mrvl_port_wred_get(_In_ const sai_object_key_t   *key,
                                       _Inout_ sai_attribute_value_t *value,
                                       _In_ uint32_t                  attr_index,
                                       _Inout_ vendor_cache_t        *cache,
                                       void                          *arg);
static sai_status_t mrvl_port_update_dscp_get(_In_ const sai_object_key_t   *key,
                                              _Inout_ sai_attribute_value_t *value,
                                              _In_ uint32_t                  attr_index,
                                              _Inout_ vendor_cache_t        *cache,
                                              void                          *arg);
static sai_status_t mrvl_port_update_dscp_set(_In_ const sai_object_key_t      *key,
                                              _In_ const sai_attribute_value_t *value,
                                              void                             *arg);
static sai_status_t mrvl_port_qos_default_tc_get(_In_ const sai_object_key_t   *key,
                                                 _Inout_ sai_attribute_value_t *value,
                                                 _In_ uint32_t                  attr_index,
                                                 _Inout_ vendor_cache_t        *cache,
                                                 void                          *arg);
static sai_status_t mrvl_port_qos_default_tc_set(_In_ const sai_object_key_t      *key,
                                                 _In_ const sai_attribute_value_t *value,
                                                 void                             *arg);
static sai_status_t mrvl_port_qos_map_id_get(_In_ const sai_object_key_t   *key,
                                             _Inout_ sai_attribute_value_t *value,
                                             _In_ uint32_t                  attr_index,
                                             _Inout_ vendor_cache_t        *cache,
                                             void                          *arg);
static sai_status_t mrvl_port_qos_map_id_set(_In_ const sai_object_key_t      *key,
                                             _In_ const sai_attribute_value_t *value,
                                             void                             *arg);
static sai_status_t mrvl_port_mirror_session_get(_In_ const sai_object_key_t   *key,
                                                 _Inout_ sai_attribute_value_t *value,
                                                 _In_ uint32_t                  attr_index,
                                                 _Inout_ vendor_cache_t        *cache,
                                                 void                          *arg);
static sai_status_t mrvl_port_mirror_session_set(_In_ const sai_object_key_t      *key,
                                                 _In_ const sai_attribute_value_t *value,
                                                 void                             *arg);
static sai_status_t mrvl_port_samplepacket_session_get(_In_ const sai_object_key_t   *key,
                                                       _Inout_ sai_attribute_value_t *value,
                                                       _In_ uint32_t                  attr_index,
                                                       _Inout_ vendor_cache_t        *cache,
                                                       void                          *arg);
static sai_status_t mrvl_port_samplepacket_session_set(_In_ const sai_object_key_t      *key,
                                                       _In_ const sai_attribute_value_t *value,
                                                       void                             *arg);
static sai_status_t mrvl_port_pfc_control_get(_In_ const sai_object_key_t   *key,
                                              _Inout_ sai_attribute_value_t *value,
                                              _In_ uint32_t                  attr_index,
                                              _Inout_ vendor_cache_t        *cache,
                                              void                          *arg);
static sai_status_t mrvl_port_pfc_control_set(_In_ const sai_object_key_t      *key,
                                              _In_ const sai_attribute_value_t *value,
                                              void                             *arg);
static sai_status_t mrvl_port_sched_get(_In_ const sai_object_key_t   *key,
                                        _Inout_ sai_attribute_value_t *value,
                                        _In_ uint32_t                  attr_index,
                                        _Inout_ vendor_cache_t        *cache,
                                        void                          *arg);
static sai_status_t mrvl_port_sched_set(_In_ const sai_object_key_t      *key,
                                        _In_ const sai_attribute_value_t *value,
                                        void                             *arg);
static sai_status_t mrvl_port_ingress_buffer_profile_list_get(_In_ const sai_object_key_t   *key,
                                                              _Inout_ sai_attribute_value_t *value,
                                                              _In_ uint32_t                  attr_index,
                                                              _Inout_ vendor_cache_t        *cache,
                                                              void                          *arg);
static sai_status_t mrvl_port_ingress_buffer_profile_list_set(_In_ const sai_object_key_t      *key,
                                                              _In_ const sai_attribute_value_t *value,
                                                              void                             *arg);
static sai_status_t mrvl_port_egress_buffer_profile_list_get(_In_ const sai_object_key_t   *key,
                                                             _Inout_ sai_attribute_value_t *value,
                                                             _In_ uint32_t                  attr_index,
                                                             _Inout_ vendor_cache_t        *cache,
                                                             void                          *arg);
static sai_status_t mrvl_port_egress_buffer_profile_list_set(_In_ const sai_object_key_t      *key,
                                                             _In_ const sai_attribute_value_t *value,
                                                             void                             *arg);
static sai_status_t mrvl_port_storm_control_policer_attr_set(_In_ const sai_object_key_t      *key,
                                                             _In_ const sai_attribute_value_t *value,
                                                             _In_ void                        *arg);
static sai_status_t mrvl_port_storm_control_policer_attr_get(_In_ const sai_object_key_t   *key,
                                                             _Inout_ sai_attribute_value_t *value,
                                                             _In_ uint32_t                  attr_index,
                                                             _Inout_ vendor_cache_t        *cache,
                                                             _In_ void                     *arg);
static sai_status_t mrvl_port_bind_mode_set(_In_ const sai_object_key_t      *key,
                                            _In_ const sai_attribute_value_t *value,
                                            _In_ void                        *arg);
static sai_status_t mrvl_port_bind_mode_get(_In_ const sai_object_key_t   *key,
                                            _Inout_ sai_attribute_value_t *value,
                                            _In_ uint32_t                  attr_index,
                                            _Inout_ vendor_cache_t        *cache,
                                            _In_ void                     *arg);
static sai_status_t mrvl_port_egress_block_set(_In_ const sai_object_key_t      *key,
                                               _In_ const sai_attribute_value_t *value,
                                               _In_ void                        *arg);
static sai_status_t mrvl_port_egress_block_get(_In_ const sai_object_key_t   *key,
                                               _Inout_ sai_attribute_value_t *value,
                                               _In_ uint32_t                  attr_index,
                                               _Inout_ vendor_cache_t        *cache,
                                               _In_ void                     *arg);

static const sai_attribute_entry_t        port_attribs[] = {
    { SAI_PORT_ATTR_TYPE, false, false, false, true,
      "Port type", SAI_ATTR_VAL_TYPE_S32 },
    { SAI_PORT_ATTR_OPER_STATUS, false, false, false, true,
      "Port operational status", SAI_ATTR_VAL_TYPE_S32 },
	{ SAI_PORT_ATTR_HW_LANE_LIST, false/*true*/, true, false, true,
	  "Port hw lane", SAI_ATTR_VAL_TYPE_U32LIST },
    { SAI_PORT_ATTR_SUPPORTED_BREAKOUT_MODE_TYPE, false, false, false, true,
	  "Port breakout mode(s) supported", SAI_ATTR_VAL_TYPE_S32LIST },
    { SAI_PORT_ATTR_CURRENT_BREAKOUT_MODE_TYPE, false, false, false, true,
	  "Port current breakout mode", SAI_ATTR_VAL_TYPE_S32 },
    { SAI_PORT_ATTR_SUPPORTED_SPEED, false, false, false, true,
      "Port supported speed", SAI_ATTR_VAL_TYPE_U32LIST },
    { SAI_PORT_ATTR_SUPPORTED_FEC_MODE, false, false, false, true,
	  "Port supported FEC mode(s)", SAI_ATTR_VAL_TYPE_S32LIST },
    { SAI_PORT_ATTR_NUMBER_OF_INGRESS_PRIORITY_GROUPS, false, false, false, true,
	  "Port ingress priority group count", SAI_ATTR_VAL_TYPE_U32},
	{ SAI_PORT_ATTR_INGRESS_PRIORITY_GROUP_LIST, false, false, false, true,
	  "Port ingress priority groups", SAI_ATTR_VAL_TYPE_OBJLIST},
    { SAI_PORT_ATTR_SPEED, true, true, true, true,
      "Port speed", SAI_ATTR_VAL_TYPE_U32 },
    { SAI_PORT_ATTR_FULL_DUPLEX_MODE, false, false, false, true,
	  "Port full duplex setting", SAI_ATTR_VAL_TYPE_BOOL },
    { SAI_PORT_ATTR_AUTO_NEG_MODE, false, false, false, true,
	  "Port auto negotiation configuration", SAI_ATTR_VAL_TYPE_BOOL },
    { SAI_PORT_ATTR_ADMIN_STATE, false, false, true, true,
      "Port admin state", SAI_ATTR_VAL_TYPE_BOOL },
    { SAI_PORT_ATTR_MEDIA_TYPE, false, false, false, true,
	  "Port media type", SAI_ATTR_VAL_TYPE_S32 },
    { SAI_PORT_ATTR_PORT_VLAN_ID, false, false, true, true,
      "Port default vlan", SAI_ATTR_VAL_TYPE_U16 },
    { SAI_PORT_ATTR_DEFAULT_VLAN_PRIORITY, false, false, true, true,
      "Port default vlan priority", SAI_ATTR_VAL_TYPE_U8 },
    { SAI_PORT_ATTR_INGRESS_FILTERING, false, false, false, true,
	  "Port ingress filtering", SAI_ATTR_VAL_TYPE_BOOL },
    { SAI_PORT_ATTR_DROP_UNTAGGED, false, false, false, true,
	  "Port drop of untagged frames on ingress", SAI_ATTR_VAL_TYPE_BOOL },
    { SAI_PORT_ATTR_DROP_TAGGED, false, false, false, true,
	  "Port drop of tagged frames on ingress", SAI_ATTR_VAL_TYPE_BOOL },
    { SAI_PORT_ATTR_INTERNAL_LOOPBACK_MODE, false, false, false, true,
	  "Port internal loopback control", SAI_ATTR_VAL_TYPE_S32 },
    { SAI_PORT_ATTR_FEC_MODE, false, false, false, true,
	  "Port FEC control", SAI_ATTR_VAL_TYPE_S32 },
    { SAI_PORT_ATTR_UPDATE_DSCP, false, false, false, true,
	  "Port update DSCP of outgoing packets", SAI_ATTR_VAL_TYPE_BOOL },
    { SAI_PORT_ATTR_MTU, false, false, false, true,
	  "Port MTU", SAI_ATTR_VAL_TYPE_U32 },
    { SAI_PORT_ATTR_FLOOD_STORM_CONTROL_POLICER_ID, false, false, false, true,
	  "Port enable flood storm control policer", SAI_ATTR_VAL_TYPE_OID },
    { SAI_PORT_ATTR_BROADCAST_STORM_CONTROL_POLICER_ID, false, false, false, true,
	  "Port enable broadcast storm control policer", SAI_ATTR_VAL_TYPE_OID },
    { SAI_PORT_ATTR_MULTICAST_STORM_CONTROL_POLICER_ID, false, false, false, true,
	  "Port enable multicast storm control policer", SAI_ATTR_VAL_TYPE_OID },
    { SAI_PORT_ATTR_GLOBAL_FLOW_CONTROL_MODE, false, false, true, true,
      "Port global flow control", SAI_ATTR_VAL_TYPE_S32 },
    { SAI_PORT_ATTR_INGRESS_ACL, false, true, true, true,
      "Port bind point for ingress ACL objects", SAI_ATTR_VAL_TYPE_OID },
    { SAI_PORT_ATTR_EGRESS_ACL, false, true, true, true,
      "Port bind point for egress ACL objects", SAI_ATTR_VAL_TYPE_OID },
    { SAI_PORT_ATTR_INGRESS_MIRROR_SESSION, false, false, false, true,
	  "Port enable/disable ingress mirror session", SAI_ATTR_VAL_TYPE_OBJLIST },
    { SAI_PORT_ATTR_EGRESS_MIRROR_SESSION, false, false, false, true,
	  "Port enable/disable egress mirror session", SAI_ATTR_VAL_TYPE_OBJLIST },
    { SAI_PORT_ATTR_INGRESS_SAMPLEPACKET_ENABLE, false, false, false, true,
	  "Port enable/disable ingress samplepacket session", SAI_ATTR_VAL_TYPE_OID },
    { SAI_PORT_ATTR_EGRESS_SAMPLEPACKET_ENABLE, false, false, false, true,
	  "Port enable/disable egress samplepacket session", SAI_ATTR_VAL_TYPE_OID },
    { SAI_PORT_ATTR_QOS_DEFAULT_TC, false, false, false, true,
	  "Port default TC mapping", SAI_ATTR_VAL_TYPE_U8 },
    { SAI_PORT_ATTR_QOS_DOT1P_TO_TC_MAP, false, false, false, true,
	  "Port enable DOT1P->TC map", SAI_ATTR_VAL_TYPE_OID },
    { SAI_PORT_ATTR_QOS_DOT1P_TO_COLOR_MAP, false, false, false, true,
	  "Port enable DOT1P->COLOR map", SAI_ATTR_VAL_TYPE_OID },
    { SAI_PORT_ATTR_QOS_DSCP_TO_TC_MAP, false, false, false, true,
	  "Port enable DSCP->TC map", SAI_ATTR_VAL_TYPE_OID },
    { SAI_PORT_ATTR_QOS_DSCP_TO_COLOR_MAP, false, false, false, true,
	  "Port enable DSCP->COLOR map", SAI_ATTR_VAL_TYPE_OID },
    { SAI_PORT_ATTR_QOS_TC_AND_COLOR_TO_DOT1P_MAP, false, false, false, true,
	  "Port enable TC+COLOR->DOT1P map", SAI_ATTR_VAL_TYPE_OID },
    { SAI_PORT_ATTR_QOS_TC_AND_COLOR_TO_DSCP_MAP, false, false, false, true,
	  "Port enable TC+COLOR->DSCP map", SAI_ATTR_VAL_TYPE_OID },
    { SAI_PORT_ATTR_QOS_TC_TO_QUEUE_MAP, false, false, false, true,
	  "Port enable TC->QUEUE map", SAI_ATTR_VAL_TYPE_OID },
    { SAI_PORT_ATTR_QOS_TC_TO_PRIORITY_GROUP_MAP, false, false, false, true,
	  "Port enable TC->Priority Group map", SAI_ATTR_VAL_TYPE_OID },
    { SAI_PORT_ATTR_QOS_PFC_PRIORITY_TO_PRIORITY_GROUP_MAP, false, false, false, true,
	  "Port enable PFC Priority->Priority Group map", SAI_ATTR_VAL_TYPE_OID },
    { SAI_PORT_ATTR_QOS_PFC_PRIORITY_TO_QUEUE_MAP, false, false, false, true,
	  "Port enable PFC Priority->QUEUE map", SAI_ATTR_VAL_TYPE_OID },
    { SAI_PORT_ATTR_PRIORITY_FLOW_CONTROL, false, false, false, true,
	  "Port enable/disable PFC", SAI_ATTR_VAL_TYPE_U8 },
    { SAI_PORT_ATTR_QOS_WRED_PROFILE_ID, false, false, false, true,
	  "Port attach WRED profile id", SAI_ATTR_VAL_TYPE_OID },
    { SAI_PORT_ATTR_QOS_SCHEDULER_PROFILE_ID, false, false, false, true,
	  "Port scheduler profile id", SAI_ATTR_VAL_TYPE_OID },
    { SAI_PORT_ATTR_QOS_NUMBER_OF_QUEUES, false, false, false, true,
	  "Port qos number of queues", SAI_ATTR_VAL_TYPE_U32 },
	{ SAI_PORT_ATTR_QOS_QUEUE_LIST, false, false, false, true,
	  "Port qos queue list", SAI_ATTR_VAL_TYPE_OBJLIST },
    { SAI_PORT_ATTR_QOS_NUMBER_OF_SCHEDULER_GROUPS, false, false, false, true,
      "Port qos number of scheduled groups", SAI_ATTR_VAL_TYPE_U32},
    { SAI_PORT_ATTR_QOS_SCHEDULER_GROUP_LIST, false, false, false, true,
	  "Port scheduler group list", SAI_ATTR_VAL_TYPE_OBJLIST },
    { SAI_PORT_ATTR_QOS_INGRESS_BUFFER_PROFILE_LIST, false, false, false, true,
	  "Port ingress buffer profile list", SAI_ATTR_VAL_TYPE_OBJLIST },
    { SAI_PORT_ATTR_QOS_EGRESS_BUFFER_PROFILE_LIST, false, false, false, true,
	  "Port egress buffer profile list", SAI_ATTR_VAL_TYPE_OBJLIST },
    { SAI_PORT_ATTR_POLICER_ID, false, false, false, true,
	  "Port attached policer id", SAI_ATTR_VAL_TYPE_OID },
    { SAI_PORT_ATTR_BIND_MODE, false, false, false, true,
	  "Port bind mode", SAI_ATTR_VAL_TYPE_S32 },
    { SAI_PORT_ATTR_EGRESS_BLOCK_PORT_LIST, false, false, false, true,
	  "Port egress block port list", SAI_ATTR_VAL_TYPE_OBJLIST },
    { END_FUNCTIONALITY_ATTRIBS_ID, false, false, false, false,
      "", SAI_ATTR_VAL_TYPE_UNDETERMINED }
};

static const sai_vendor_attribute_entry_t port_vendor_attribs[] = {
    { SAI_PORT_ATTR_TYPE,
      { false, false, false, true },
      { false, false, false, true },
      mrvl_port_type_get, NULL,
      NULL, NULL },
    { SAI_PORT_ATTR_OPER_STATUS,
      { false, false, false, true },
      { false, false, false, true },
      mrvl_port_state_get, (void*)SAI_PORT_ATTR_OPER_STATUS,
      NULL, NULL },
    { SAI_PORT_ATTR_HW_LANE_LIST,
      { true, false, false, true },
      { true, false, false, true },
      mrvl_port_hw_lane_get, NULL,
      NULL, NULL },
    { SAI_PORT_ATTR_SUPPORTED_BREAKOUT_MODE_TYPE,
      { false, false, false, true },
      { false, false, false, true },
      mrvl_port_supported_breakout_get, NULL,
      NULL, NULL },
    { SAI_PORT_ATTR_CURRENT_BREAKOUT_MODE_TYPE,
      { false, false, false, true },
      { false, false, false, true },
      mrvl_port_current_breakout_get, NULL,
      NULL, NULL },
    { SAI_PORT_ATTR_SUPPORTED_SPEED,
      { false, false, false, true },
      { false, false, false, true },
      mrvl_port_supported_speed_get, NULL,
      NULL, NULL },
    { SAI_PORT_ATTR_SUPPORTED_FEC_MODE,
      { false, false, false, true },
      { false, false, false, true },
      mrvl_port_supported_fec_mode_get, NULL,
      NULL, NULL },
    { SAI_PORT_ATTR_NUMBER_OF_INGRESS_PRIORITY_GROUPS,
      { false, false, false, true },
      { false, false, false, true },
      mrvl_port_number_of_priority_groups_get, NULL,
      NULL, NULL },
    { SAI_PORT_ATTR_INGRESS_PRIORITY_GROUP_LIST,
      { false, false, false, true },
      { false, false, false, true },
      mrvl_port_priority_group_list_get, NULL,
      NULL, NULL },
    { SAI_PORT_ATTR_SPEED,
      { true, false, true, true },
      { true, false, true, true },
      mrvl_port_speed_get, NULL,
      mrvl_port_speed_set, NULL },
    { SAI_PORT_ATTR_FULL_DUPLEX_MODE,
      { false, false, false, true },
      { false, false, true, true },
      mrvl_port_duplex_get, NULL,
      NULL, NULL },
    { SAI_PORT_ATTR_AUTO_NEG_MODE,
      { false, false, true, true },
      { false, false, true, true },
      mrvl_port_auto_negotiation_get, NULL,
      mrvl_port_auto_negotiation_set, NULL },
    { SAI_PORT_ATTR_ADMIN_STATE,
      { false, false, true, true },
      { false, false, true, true },
      mrvl_port_state_get, (void*)SAI_PORT_ATTR_ADMIN_STATE,
      mrvl_port_state_set, NULL },
    { SAI_PORT_ATTR_MEDIA_TYPE,
      { false, false, false, false },
      { false, false, true, true },
      NULL, NULL,
      NULL, NULL },
    { SAI_PORT_ATTR_PORT_VLAN_ID,
      { false, false, true, true },
      { false, false, true, true },
      mrvl_port_default_vlan_get, NULL,
      mrvl_port_default_vlan_set, NULL },
    { SAI_PORT_ATTR_DEFAULT_VLAN_PRIORITY,
      { false, false, true, true },
      { false, false, true, true },
      mrvl_port_default_vlan_prio_get, NULL,
      mrvl_port_default_vlan_prio_set, NULL },
    { SAI_PORT_ATTR_INGRESS_FILTERING,
      { false, false, true, true },
      { false, false, true, true },
      mrvl_port_ingress_filter_get, NULL,
      mrvl_port_ingress_filter_set, NULL },
    { SAI_PORT_ATTR_DROP_UNTAGGED,
      { false, false, true, true },
      { false, false, true, true },
      mrvl_port_drop_tags_get, (void*)SAI_PORT_ATTR_DROP_UNTAGGED,
      mrvl_port_drop_tags_set, (void*)SAI_PORT_ATTR_DROP_UNTAGGED },
    { SAI_PORT_ATTR_DROP_TAGGED,
      { false, false, true, true },
      { false, false, true, true },
      mrvl_port_drop_tags_get, (void*)SAI_PORT_ATTR_DROP_TAGGED,
      mrvl_port_drop_tags_set, (void*)SAI_PORT_ATTR_DROP_TAGGED },
    { SAI_PORT_ATTR_INTERNAL_LOOPBACK_MODE,
      { false, false, true, true },
      mrvl_port_internal_loopback_get, NULL,
      mrvl_port_internal_loopback_set, NULL },
    { SAI_PORT_ATTR_FEC_MODE,
      { true, false, true, true },
      { true, false, true, true },
      mrvl_port_fec_get, NULL,
      mrvl_port_fec_set, NULL },
    { SAI_PORT_ATTR_UPDATE_DSCP,
      { false, false, true, true },
      { false, false, true, true },
      mrvl_port_update_dscp_get, NULL,
      mrvl_port_update_dscp_set, NULL },
    { SAI_PORT_ATTR_MTU,
      { false, false, true, true },
      { false, false, true, true },
      mrvl_port_mtu_get, NULL,
      mrvl_port_mtu_set, NULL },
    { SAI_PORT_ATTR_FLOOD_STORM_CONTROL_POLICER_ID,
      { false, false, true, true},
      { false, false, true, true },
      mrvl_port_storm_control_policer_attr_get, NULL,
      mrvl_port_storm_control_policer_attr_set, NULL },
    { SAI_PORT_ATTR_BROADCAST_STORM_CONTROL_POLICER_ID,
      { false, false, true, true},
      { false, false, true, true },
      mrvl_port_storm_control_policer_attr_get, NULL,
      mrvl_port_storm_control_policer_attr_set, NULL },
    { SAI_PORT_ATTR_MULTICAST_STORM_CONTROL_POLICER_ID,
      { false, false, true, true},
      { false, false, true, true },
      mrvl_port_storm_control_policer_attr_get, NULL,
      mrvl_port_storm_control_policer_attr_set, NULL },
    { SAI_PORT_ATTR_GLOBAL_FLOW_CONTROL_MODE,
      { false, false, true, true },
      { false, false, true, true },
      mrvl_port_fc_get, NULL,
      mrvl_port_fc_set, NULL },
    { SAI_PORT_ATTR_INGRESS_ACL,
      { true, false, true, true },
      { true, false, true, true },
      mrvl_port_acl_binding_get, NULL, 
      mrvl_port_acl_binding_set, NULL },
    { SAI_PORT_ATTR_EGRESS_ACL,
      { true, false, true, true },
      { true, false, true, true },
      mrvl_port_acl_binding_get, NULL, 
      mrvl_port_acl_binding_set, NULL },
    { SAI_PORT_ATTR_INGRESS_MIRROR_SESSION,
      { false, false, true, true },
      { false, false, true, true },
      mrvl_port_mirror_session_get, NULL,
      mrvl_port_mirror_session_set, NULL },
    { SAI_PORT_ATTR_EGRESS_MIRROR_SESSION,
      { false, false, true, true },
      { false, false, true, true },
      mrvl_port_mirror_session_get, NULL,
      mrvl_port_mirror_session_set, NULL },
    { SAI_PORT_ATTR_INGRESS_SAMPLEPACKET_ENABLE,
      { false, false, true, true },
      { false, false, true, true },
      mrvl_port_samplepacket_session_get, NULL,
      mrvl_port_samplepacket_session_set, NULL },
    { SAI_PORT_ATTR_EGRESS_SAMPLEPACKET_ENABLE,
      { false, false, false, false },
      { false, false, true, true },
      mrvl_port_samplepacket_session_get, NULL,
      mrvl_port_samplepacket_session_set, NULL },
    { SAI_PORT_ATTR_QOS_DEFAULT_TC,
      { false, false, true, true },
      { false, false, true, true },
      mrvl_port_qos_default_tc_get, NULL,
      mrvl_port_qos_default_tc_set, NULL },
    { SAI_PORT_ATTR_QOS_DOT1P_TO_TC_MAP,
      { false, false, true, true },
      { false, false, true, true },
      mrvl_port_qos_map_id_get, (void*)SAI_QOS_MAP_TYPE_DOT1P_TO_TC,
      mrvl_port_qos_map_id_set, (void*)SAI_QOS_MAP_TYPE_DOT1P_TO_TC },
    { SAI_PORT_ATTR_QOS_DOT1P_TO_COLOR_MAP,
      { false, false, true, true },
      { false, false, true, true },
      mrvl_port_qos_map_id_get, (void*)SAI_QOS_MAP_TYPE_DOT1P_TO_COLOR,
      mrvl_port_qos_map_id_set, (void*)SAI_QOS_MAP_TYPE_DOT1P_TO_COLOR },
    { SAI_PORT_ATTR_QOS_DSCP_TO_TC_MAP,
      { false, false, true, true },
      { false, false, true, true },
      mrvl_port_qos_map_id_get, (void*)SAI_QOS_MAP_TYPE_DSCP_TO_TC,
      mrvl_port_qos_map_id_set, (void*)SAI_QOS_MAP_TYPE_DSCP_TO_TC },
    { SAI_PORT_ATTR_QOS_DSCP_TO_COLOR_MAP,
      { false, false, true, true },
      { false, false, true, true },
      mrvl_port_qos_map_id_get, (void*)SAI_QOS_MAP_TYPE_DSCP_TO_COLOR,
      mrvl_port_qos_map_id_set, (void*)SAI_QOS_MAP_TYPE_DSCP_TO_COLOR },
    { SAI_PORT_ATTR_QOS_TC_AND_COLOR_TO_DOT1P_MAP,
      { false, false, true, true },
      { false, false, true, true },
      mrvl_port_qos_map_id_get, (void*)SAI_QOS_MAP_TYPE_TC_AND_COLOR_TO_DOT1P,
      mrvl_port_qos_map_id_set, (void*)SAI_QOS_MAP_TYPE_TC_AND_COLOR_TO_DOT1P },
    { SAI_PORT_ATTR_QOS_TC_AND_COLOR_TO_DSCP_MAP,
      { false, false, true, true },
      { false, false, true, true },
      mrvl_port_qos_map_id_get, (void*)SAI_QOS_MAP_TYPE_TC_AND_COLOR_TO_DSCP,
      mrvl_port_qos_map_id_set, (void*)SAI_QOS_MAP_TYPE_TC_AND_COLOR_TO_DSCP },
    { SAI_PORT_ATTR_QOS_TC_TO_QUEUE_MAP,
      { false, false, true, true },
      { false, false, true, true },
      mrvl_port_qos_map_id_get, (void*)SAI_QOS_MAP_TYPE_TC_TO_QUEUE,
      mrvl_port_qos_map_id_set, (void*)SAI_QOS_MAP_TYPE_TC_TO_QUEUE },
    { SAI_PORT_ATTR_QOS_TC_TO_PRIORITY_GROUP_MAP,
      { false, false, true, true },
      { false, false, true, true },
      mrvl_port_qos_map_id_get, (void*)SAI_QOS_MAP_TYPE_TC_TO_PRIORITY_GROUP,
      mrvl_port_qos_map_id_set, (void*)SAI_QOS_MAP_TYPE_TC_TO_PRIORITY_GROUP },
    { SAI_PORT_ATTR_QOS_PFC_PRIORITY_TO_PRIORITY_GROUP_MAP,
      { false, false, true, true },
      { false, false, true, true },
      mrvl_port_qos_map_id_get, (void*)SAI_QOS_MAP_TYPE_PFC_PRIORITY_TO_PRIORITY_GROUP,
      mrvl_port_qos_map_id_set, (void*)SAI_QOS_MAP_TYPE_PFC_PRIORITY_TO_PRIORITY_GROUP },
    { SAI_PORT_ATTR_QOS_PFC_PRIORITY_TO_QUEUE_MAP,
      { false, false, true, true },
      { false, false, true, true },
      mrvl_port_qos_map_id_get, (void*)SAI_QOS_MAP_TYPE_PFC_PRIORITY_TO_QUEUE,
      mrvl_port_qos_map_id_set, (void*)SAI_QOS_MAP_TYPE_PFC_PRIORITY_TO_QUEUE },
    { SAI_PORT_ATTR_PRIORITY_FLOW_CONTROL,
      { false, false, true, true },
      { false, false, true, true },
      mrvl_port_pfc_control_get, NULL,
      mrvl_port_pfc_control_set, NULL },
    { SAI_PORT_ATTR_QOS_WRED_PROFILE_ID,
      { false, false, true, true },
      { false, false, true, true },
      mrvl_port_wred_get, NULL,
      mrvl_port_wred_set, NULL },
    { SAI_PORT_ATTR_QOS_SCHEDULER_PROFILE_ID,
      { false, false, true, true },
      { false, false, true, true },
      mrvl_port_sched_get, NULL,
      mrvl_port_sched_set, NULL },
    { SAI_PORT_ATTR_QOS_NUMBER_OF_QUEUES,
      { false, false, false, true },
      { false, false, false, true },
      mrvl_port_qos_num_queues_get, NULL,
      NULL, NULL},
    { SAI_PORT_ATTR_QOS_QUEUE_LIST,
      { false, false, false, true },
      { false, false, false, true },
      mrvl_port_qos_queue_list_get, NULL,
      NULL, NULL },
    { SAI_PORT_ATTR_QOS_NUMBER_OF_SCHEDULER_GROUPS,
      { false, false, false, true },
      { false, false, false, true },
      mrvl_port_sched_groups_num_get, NULL,
      NULL, NULL },
    { SAI_PORT_ATTR_QOS_SCHEDULER_GROUP_LIST,
      { false, false, false, true },
      { false, false, false, true },
      mrvl_port_sched_groups_list_get, NULL,
      NULL, NULL },
    { SAI_PORT_ATTR_QOS_INGRESS_BUFFER_PROFILE_LIST,
      { false, false, true, true },
      { false, false, true, true },
      mrvl_port_ingress_buffer_profile_list_get, NULL,
      mrvl_port_ingress_buffer_profile_list_set, NULL },
    { SAI_PORT_ATTR_QOS_EGRESS_BUFFER_PROFILE_LIST,
      { false, false, true, true },
      { false, false, true, true },
      mrvl_port_egress_buffer_profile_list_get, NULL,
      mrvl_port_egress_buffer_profile_list_set, NULL },
    { SAI_PORT_ATTR_POLICER_ID,
      { false, false, true, true },
      { false, false, true, true },
      mrvl_port_storm_control_policer_attr_get, NULL,
      mrvl_port_storm_control_policer_attr_set, NULL},
    { SAI_PORT_ATTR_BIND_MODE,
      { true, false, true, true },
      { true, false, true, true },
      mrvl_port_bind_mode_get, NULL,
      mrvl_port_bind_mode_set, NULL },
    { SAI_PORT_ATTR_EGRESS_BLOCK_PORT_LIST,
      { true, false, true, true },
      { true, false, true, true },
      mrvl_port_egress_block_get, NULL,
      mrvl_port_egress_block_set, NULL },
    { END_FUNCTIONALITY_ATTRIBS_ID,
      { false, false, false, false },
      { false, false, false, false },
      NULL, NULL,
      NULL, NULL }
};

/* Operational Status [sai_port_oper_status_t] */
/* Admin Mode [bool] */
sai_status_t mrvl_port_state_get(_In_ const sai_object_key_t   *key,
                                 _Inout_ sai_attribute_value_t *value,
                                 _In_ uint32_t                  attr_index,
                                 _Inout_ vendor_cache_t        *cache,
                                 void                          *arg)
{
    sai_status_t status;
    uint32_t     port_id;

    FPA_STATUS                  fpa_status;
    FPA_PORT_PROPERTIES_STC     portProperties;
        
    MRVL_SAI_LOG_ENTER();

    assert((SAI_PORT_ATTR_OPER_STATUS == (PTR_TO_INT)arg) || (SAI_PORT_ATTR_ADMIN_STATE == (PTR_TO_INT)arg));

    if (SAI_STATUS_SUCCESS != (status = mrvl_sai_utl_object_to_type(key->key.object_id, SAI_OBJECT_TYPE_PORT, &port_id))) {
        return status;
    }

    if (SAI_PORT_ATTR_OPER_STATUS == (PTR_TO_INT)arg) {
        portProperties.flags = FPA_PORT_PROPERTIES_STATE_FLAG;
    } else {
        portProperties.flags = FPA_PORT_PROPERTIES_CONFIG_FLAG;
    }
    
    fpa_status = fpaLibPortPropertiesGet(SAI_DEFAULT_ETH_SWID_CNS,
                                         port_id,
                                         &portProperties);
    if (FPA_OK != fpa_status) {
        MRVL_SAI_LOG_ERR("Failed to get port %d attributes (speed)\n", port_id);
        return SAI_STATUS_FAILURE;
    }

    if (SAI_PORT_ATTR_OPER_STATUS == (PTR_TO_INT)arg) {
        if (portProperties.state & FPA_PORT_STATE_LINK_DOWN) {
            value->s32 = SAI_PORT_OPER_STATUS_DOWN;
        } else {
            value->s32 = SAI_PORT_OPER_STATUS_UP;
        }
    } else {
        if (portProperties.config & FPA_PORT_CONFIG_DOWN) {
            value->booldata = false;
        } else {
            value->booldata = true;
        }
    }
        
    MRVL_SAI_LOG_EXIT();
    return SAI_STATUS_SUCCESS;
}

/* Admin Mode [bool] */
sai_status_t mrvl_port_state_set(_In_ const sai_object_key_t *key,
                                 _In_ const sai_attribute_value_t *value,
                                 void *arg)
{
    sai_status_t status;
    uint32_t     port_id;

    FPA_STATUS                  fpa_status;
    FPA_PORT_PROPERTIES_STC     portProperties;

    MRVL_SAI_LOG_ENTER();

    if (SAI_STATUS_SUCCESS != (status = mrvl_sai_utl_object_to_type(key->key.object_id, SAI_OBJECT_TYPE_PORT, &port_id))) {
        return status;
    }

    /* Get the current port config */
    portProperties.flags = FPA_PORT_PROPERTIES_CONFIG_FLAG;

    fpa_status = fpaLibPortPropertiesGet(SAI_DEFAULT_ETH_SWID_CNS,
                                         port_id,
                                         &portProperties);

    if (FPA_OK != fpa_status) {
        MRVL_SAI_LOG_ERR("Failed to get port %d config (admin link)\n", 
                         port_id);
        return SAI_STATUS_FAILURE;
    }

    if (true == value->booldata) {
        portProperties.config &= ~FPA_PORT_CONFIG_DOWN;
    } else {
        portProperties.config |= FPA_PORT_CONFIG_DOWN;
    }

/* do not shutdown port since no one configure no shutdown */
    portProperties.config &= ~FPA_PORT_CONFIG_DOWN;

    fpa_status = fpaLibPortPropertiesSet(SAI_DEFAULT_ETH_SWID_CNS,
                                         port_id,
                                         &portProperties);

    if (FPA_OK != fpa_status) {
        MRVL_SAI_LOG_ERR("Failed to set port %d config (admin link)\n",
                         port_id);
        return SAI_STATUS_FAILURE;
    }

    MRVL_SAI_LOG_EXIT();
    return SAI_STATUS_SUCCESS;
}

extern sai_status_t mrvl_sai_utl_fill_u32list(uint32_t *data, uint32_t count, sai_u32_list_t *list);

/* list of hw lane [sai_u32_list_t] */
sai_status_t mrvl_port_hw_lane_get(_In_ const sai_object_key_t   *key,
                                           _Inout_ sai_attribute_value_t *value,
                                           _In_ uint32_t                  attr_index,
                                           _Inout_ vendor_cache_t        *cache,
                                           void                          *arg)
{
    sai_status_t status;
    uint32_t     port_id;


    MRVL_SAI_LOG_ENTER();

    if (SAI_STATUS_SUCCESS != (status = mrvl_sai_utl_object_to_type(key->key.object_id, SAI_OBJECT_TYPE_PORT, &port_id))) {
        return status;
    }


    mrvl_sai_utl_fill_u32list(&port_id, 1, &value->u32list);

    MRVL_SAI_LOG_EXIT();
    return SAI_STATUS_SUCCESS;
}

/* number of qos queues [sai_u32_list_t] */

sai_status_t mrvl_port_qos_num_queues_get(_In_ const sai_object_key_t   *key,
                                        _Inout_ sai_attribute_value_t *value,
                                        _In_ uint32_t                  attr_index,
                                        _Inout_ vendor_cache_t        *cache,
                                        void                          *arg)
{

    MRVL_SAI_LOG_ENTER();
    value->u32 = 1;

    MRVL_SAI_LOG_EXIT();
    return SAI_STATUS_SUCCESS;

}

extern sai_status_t mrvl_sai_utl_fill_objlist(sai_object_id_t *data, uint32_t count, sai_object_list_t *list);

sai_status_t mrvl_port_qos_queue_list_get(_In_ const sai_object_key_t   *key,
                                        _Inout_ sai_attribute_value_t *value,
                                        _In_ uint32_t                  attr_index,
                                        _Inout_ vendor_cache_t        *cache,
                                        void                          *arg)
{

    sai_status_t status = SAI_STATUS_SUCCESS;
    sai_object_id_t data_obj;

    MRVL_SAI_LOG_ENTER();
  
    if (SAI_STATUS_SUCCESS != (status = mrvl_sai_utl_create_object(SAI_OBJECT_TYPE_QUEUE, 1, &data_obj))) {
        MRVL_SAI_LOG_ERR("Failed to create object SAI_OBJECT_TYPE_QUEUE\n");
        MRVL_SAI_API_RETURN(status);
        }
    
        
    /* fill object list for SAI_OBJECT_TYPE_QUEUE */
    if (SAI_STATUS_SUCCESS != (status = mrvl_sai_utl_fill_objlist(&data_obj, 1, &value->objlist))) {
        MRVL_SAI_LOG_ERR("Failed to fill objlist for SAI_OBJECT_TYPE_QUEUE\n");
        MRVL_SAI_API_RETURN(status);
    }

    MRVL_SAI_LOG_EXIT(); 
    MRVL_SAI_API_RETURN(status);
}

sai_status_t mrvl_port_number_of_priority_groups_get(_In_ const sai_object_key_t   *key,
                                                            _Inout_ sai_attribute_value_t *value,
                                                            _In_ uint32_t                  attr_index,
                                                            _Inout_ vendor_cache_t        *cache,
                                                            void                          *arg)
{
    sai_status_t status = SAI_STATUS_SUCCESS;

    MRVL_SAI_LOG_ENTER();
    value->u32 = 1;
    MRVL_SAI_LOG_EXIT();
    return status;
}

sai_status_t mrvl_port_priority_group_list_get(_In_ const sai_object_key_t   *key,
                                                      _Inout_ sai_attribute_value_t *value,
                                                      _In_ uint32_t                  attr_index,
                                                      _Inout_ vendor_cache_t        *cache,
                                                      void                          *arg)
{
    sai_status_t     status = SAI_STATUS_SUCCESS;
    sai_object_id_t data_obj;

    MRVL_SAI_LOG_ENTER();

    /* create SAI priority group object */    
    if (SAI_STATUS_SUCCESS != (status = mrvl_sai_utl_create_object(SAI_OBJECT_TYPE_INGRESS_PRIORITY_GROUP, 1, &data_obj))) {
        MRVL_SAI_API_RETURN(status);
    }
    
    /* fill object list for SAI_OBJECT_TYPE_INGRESS_PRIORITY_GROUP */
    if (SAI_STATUS_SUCCESS != (status = mrvl_sai_utl_fill_objlist(&data_obj ,1, &value->objlist))) {
        MRVL_SAI_LOG_ERR("Failed to fill objlist for SAI_OBJECT_TYPE_INGRESS_PRIORITY_GROUP\n");
        MRVL_SAI_API_RETURN(status);
    }

    MRVL_SAI_LOG_EXIT();
    return status;
}

/** Number of Scheduler groups on port [uint32_t]*/
static sai_status_t mrvl_port_sched_groups_num_get(_In_ const sai_object_key_t   *key,
                                                   _Inout_ sai_attribute_value_t *value,
                                                   _In_ uint32_t                  attr_index,
                                                   _Inout_ vendor_cache_t        *cache,
                                                   void                          *arg)
{
    sai_status_t        status;
    uint32_t     port_id;

    MRVL_SAI_LOG_ENTER();

    status = mrvl_sai_utl_object_to_type(key->key.object_id, SAI_OBJECT_TYPE_PORT, &port_id);
    if (status != SAI_STATUS_SUCCESS) {
        return status;
    }

    value->u32 = 1;

    MRVL_SAI_LOG_EXIT();
    return SAI_STATUS_SUCCESS;
}

static sai_status_t mrvl_port_sched_groups_list_get(_In_ const sai_object_key_t   *key,
                                                    _Inout_ sai_attribute_value_t *value,
                                                    _In_ uint32_t                  attr_index,
                                                    _Inout_ vendor_cache_t        *cache,
                                                    void                          *arg)
{
    sai_status_t        status = SAI_STATUS_SUCCESS;
    uint32_t    port_id;
    sai_object_id_t data_obj;

    MRVL_SAI_LOG_ENTER();

    status = mrvl_sai_utl_object_to_type(key->key.object_id, SAI_OBJECT_TYPE_PORT, &port_id);
    if (status != SAI_STATUS_SUCCESS) {
        return status;
    }

    /* create SAI scheduler group object */    
    if (SAI_STATUS_SUCCESS != (status = mrvl_sai_utl_create_object(SAI_OBJECT_TYPE_SCHEDULER_GROUP, 1, &data_obj))) {
        MRVL_SAI_API_RETURN(status);
    }
    
    /* fill object list for SAI_OBJECT_TYPE_SCHEDULER_GROUP */
    if (SAI_STATUS_SUCCESS != (status = mrvl_sai_utl_fill_objlist(&data_obj ,1, &value->objlist))) {
        MRVL_SAI_LOG_ERR("Failed to fill objlist for SAI_OBJECT_TYPE_SCHEDULER_GROUP\n");
        MRVL_SAI_API_RETURN(status);
    }

    MRVL_SAI_LOG_EXIT();
    return SAI_STATUS_SUCCESS;
}



/* list of supported port speed in Mbps [sai_u32_list_t] */
sai_status_t mrvl_port_supported_speed_get(_In_ const sai_object_key_t   *key,
                                           _Inout_ sai_attribute_value_t *value,
                                           _In_ uint32_t                  attr_index,
                                           _Inout_ vendor_cache_t        *cache,
                                           void                          *arg)
{
    sai_status_t status;
    uint32_t     port_id;
    uint32_t     num_of_supported_speed;

    FPA_STATUS                  fpa_status;
    FPA_PORT_PROPERTIES_STC     portProperties;
        
    MRVL_SAI_LOG_ENTER();

    if (SAI_STATUS_SUCCESS != (status = mrvl_sai_utl_object_to_type(key->key.object_id, SAI_OBJECT_TYPE_PORT, &port_id))) {
        return status;
    }

    portProperties.flags = FPA_PORT_PROPERTIES_SUPPORTED_FLAG;
        
    fpa_status = fpaLibPortPropertiesGet(SAI_DEFAULT_ETH_SWID_CNS,
                                         port_id,
                                         &portProperties);
    if (FPA_OK != fpa_status) {
        MRVL_SAI_LOG_ERR("Failed to get port %d supported (speed)\n", port_id);
        return SAI_STATUS_FAILURE;
    }

    num_of_supported_speed = 0;

    if( (FPA_PORT_FEAT_10MB_HD | FPA_PORT_FEAT_10MB_FD) & 
                                                portProperties.supportedBmp) {
        if(num_of_supported_speed+1 > value->u32list.count) {
            return SAI_STATUS_BUFFER_OVERFLOW;
        }
        value->u32list.list[num_of_supported_speed++] = SAI_PORT_SPEED_10M;
    }
    
    if( (FPA_PORT_FEAT_100MB_HD | FPA_PORT_FEAT_100MB_FD) & 
                                                portProperties.supportedBmp) {
        if(num_of_supported_speed+1 > value->u32list.count) {
            return SAI_STATUS_BUFFER_OVERFLOW;
        }
        value->u32list.list[num_of_supported_speed++] = SAI_PORT_SPEED_100M;
    }
            
    if( FPA_PORT_FEAT_1GB_FD & portProperties.supportedBmp) {
        if(num_of_supported_speed+1 > value->u32list.count) {
            return SAI_STATUS_BUFFER_OVERFLOW;
        }
        value->u32list.list[num_of_supported_speed++] = SAI_PORT_SPEED_1G;
    }

    if( FPA_PORT_FEAT_2_5GB_FD & portProperties.supportedBmp) {
        if(num_of_supported_speed+1 > value->u32list.count) {
            return SAI_STATUS_BUFFER_OVERFLOW;
        }
        value->u32list.list[num_of_supported_speed++] = SAI_PORT_SPEED_2_5G;
    }

    if( FPA_PORT_FEAT_10GB_FD & portProperties.supportedBmp) {
        if(num_of_supported_speed+1 > value->u32list.count) {
            return SAI_STATUS_BUFFER_OVERFLOW;
        }
        value->u32list.list[num_of_supported_speed++] = SAI_PORT_SPEED_10G;
    }

    if( FPA_PORT_FEAT_20GB_FD & portProperties.supportedBmp) {
        if(num_of_supported_speed+1 > value->u32list.count) {
            return SAI_STATUS_BUFFER_OVERFLOW;
        }
        value->u32list.list[num_of_supported_speed++] = SAI_PORT_SPEED_20G;
    }

    if( FPA_PORT_FEAT_25GB_FD & portProperties.supportedBmp) {
        if(num_of_supported_speed+1 > value->u32list.count) {
            return SAI_STATUS_BUFFER_OVERFLOW;
        }
        value->u32list.list[num_of_supported_speed++] = SAI_PORT_SPEED_25G;
    }

    if( FPA_PORT_FEAT_40GB_FD & portProperties.supportedBmp) {
        if(num_of_supported_speed+1 > value->u32list.count) {
            return SAI_STATUS_BUFFER_OVERFLOW;
        }
        value->u32list.list[num_of_supported_speed++] = SAI_PORT_SPEED_40G;
    }

    if( FPA_PORT_FEAT_100GB_FD & portProperties.supportedBmp) {
        if(num_of_supported_speed+1 > value->u32list.count) {
            return SAI_STATUS_BUFFER_OVERFLOW;
        }
        value->u32list.list[num_of_supported_speed++] = SAI_PORT_SPEED_100G;
    }
           
    if( FPA_PORT_FEAT_1TB_FD & portProperties.supportedBmp) {
        if(num_of_supported_speed+1 > value->u32list.count) {
            return SAI_STATUS_BUFFER_OVERFLOW;
        }
        value->u32list.list[num_of_supported_speed++] = SAI_PORT_SPEED_1T;
    }
    
    value->u32list.count = num_of_supported_speed;    

    MRVL_SAI_LOG_EXIT();
    return SAI_STATUS_SUCCESS;
}

/* Speed in Mbps [uint32_t] */
sai_status_t mrvl_port_speed_get(_In_ const sai_object_key_t   *key,
                                 _Inout_ sai_attribute_value_t *value,
                                 _In_ uint32_t                  attr_index,
                                 _Inout_ vendor_cache_t        *cache,
                                 void                          *arg)
{
    sai_status_t status;
    uint32_t     port_id;

    FPA_STATUS                  fpa_status;
    FPA_PORT_PROPERTIES_STC     portProperties;
        
    MRVL_SAI_LOG_ENTER();

    if (SAI_STATUS_SUCCESS != (status = mrvl_sai_utl_object_to_type(key->key.object_id, SAI_OBJECT_TYPE_PORT, &port_id))) {
        return status;
    }

    portProperties.flags = FPA_PORT_PROPERTIES_CURRSPEED_FLAG;
        
    fpa_status = fpaLibPortPropertiesGet(SAI_DEFAULT_ETH_SWID_CNS,
                                         port_id,
                                         &portProperties);
    if (FPA_OK != fpa_status) {
        MRVL_SAI_LOG_ERR("Failed to get port %d attributes (speed)\n", port_id);
        return SAI_STATUS_FAILURE;
    }

    switch((FPA_PORT_FEAT_10MB_HD  |
            FPA_PORT_FEAT_10MB_FD  |
            FPA_PORT_FEAT_100MB_HD |
            FPA_PORT_FEAT_100MB_FD |
            FPA_PORT_FEAT_1GB_FD   |
            FPA_PORT_FEAT_2_5GB_FD |
            FPA_PORT_FEAT_10GB_FD  |
            FPA_PORT_FEAT_20GB_FD  |
            FPA_PORT_FEAT_25GB_FD  |
            FPA_PORT_FEAT_40GB_FD  |
            FPA_PORT_FEAT_100GB_FD |
            FPA_PORT_FEAT_1TB_FD) & portProperties.currSpeed) {
    case FPA_PORT_FEAT_10MB_HD:
    case FPA_PORT_FEAT_10MB_FD:
        value->u32 = SAI_PORT_SPEED_10M;
        break;

    case FPA_PORT_FEAT_100MB_HD:
    case FPA_PORT_FEAT_100MB_FD:
        value->u32 = SAI_PORT_SPEED_100M;
        break;

    case FPA_PORT_FEAT_1GB_FD:
        value->u32 = SAI_PORT_SPEED_1G;
        break;

    case FPA_PORT_FEAT_2_5GB_FD:
        value->u32 = SAI_PORT_SPEED_2_5G;
        break;

    case FPA_PORT_FEAT_10GB_FD:
        value->u32 = SAI_PORT_SPEED_10G;
        break;

    case FPA_PORT_FEAT_20GB_FD:
        value->u32 = SAI_PORT_SPEED_20G;
        break;

    case FPA_PORT_FEAT_25GB_FD:
        value->u32 = SAI_PORT_SPEED_25G;
        break;

    case FPA_PORT_FEAT_40GB_FD:
        value->u32 = SAI_PORT_SPEED_40G;
        break;

    case FPA_PORT_FEAT_100GB_FD:
        value->u32 = SAI_PORT_SPEED_100G;
        break;

    case FPA_PORT_FEAT_1TB_FD:
        value->u32 = SAI_PORT_SPEED_1T;
        break;
        
    default:
        MRVL_SAI_LOG_ERR("Unreconized port speed indication[0x%x]\n", 
                         portProperties.currSpeed);
        return SAI_STATUS_FAILURE;
    }

    MRVL_SAI_LOG_EXIT();
    return SAI_STATUS_SUCCESS;
}

/* Speed in Mbps [uint32_t] */
sai_status_t mrvl_port_speed_set(_In_ const sai_object_key_t      *key, 
                                 _In_ const sai_attribute_value_t *value, 
                                 void                             *arg)
{
    sai_status_t status;
    uint32_t     port_id;
    bool         is_half_duplex;


    FPA_STATUS                  fpa_status;
    FPA_PORT_PROPERTIES_STC     portProperties;
        
    MRVL_SAI_LOG_ENTER();

    if (SAI_STATUS_SUCCESS != (status = mrvl_sai_utl_object_to_type(key->key.object_id, SAI_OBJECT_TYPE_PORT, &port_id))) {
        return status;
    }

    /* Get the current port features */
    portProperties.flags = FPA_PORT_PROPERTIES_FEATURES_FLAG;

    fpa_status = fpaLibPortPropertiesGet(SAI_DEFAULT_ETH_SWID_CNS,
                                         port_id,
                                         &portProperties);

    if (FPA_OK != fpa_status) {
        MRVL_SAI_LOG_ERR("Failed to get port %d attributes\features (speed)\n", 
                         port_id);
        return SAI_STATUS_FAILURE;
    }

    if( (FPA_PORT_FEAT_10MB_HD & portProperties.featuresBmp) ||
        (FPA_PORT_FEAT_100MB_HD & portProperties.featuresBmp) ) {
        is_half_duplex = true;
    } else {
        is_half_duplex = false;
    }

    portProperties.featuresBmp &= ~(FPA_PORT_FEAT_10MB_HD  |
                                    FPA_PORT_FEAT_10MB_FD  |
                                    FPA_PORT_FEAT_100MB_HD |
                                    FPA_PORT_FEAT_100MB_FD |
                                    FPA_PORT_FEAT_1GB_FD   |
                                    FPA_PORT_FEAT_2_5GB_FD |
                                    FPA_PORT_FEAT_10GB_FD  |
                                    FPA_PORT_FEAT_20GB_FD  |
                                    FPA_PORT_FEAT_25GB_FD  |
                                    FPA_PORT_FEAT_40GB_FD  |
                                    FPA_PORT_FEAT_100GB_FD |
                                    FPA_PORT_FEAT_1TB_FD);

    switch(value->u32) {
    case SAI_PORT_SPEED_10M:
        if (true == is_half_duplex) {
            portProperties.featuresBmp |= FPA_PORT_FEAT_10MB_HD;
        } else {
            portProperties.featuresBmp |= FPA_PORT_FEAT_10MB_FD;
        }
        break;

    case SAI_PORT_SPEED_100M:
        if (true == is_half_duplex) {
            portProperties.featuresBmp |= FPA_PORT_FEAT_100MB_HD;
        } else {
            portProperties.featuresBmp |= FPA_PORT_FEAT_100MB_FD;
        }
        break;

    case SAI_PORT_SPEED_1G:
        portProperties.featuresBmp |= FPA_PORT_FEAT_1GB_FD;
        break;

    case SAI_PORT_SPEED_2_5G:
        portProperties.featuresBmp |= FPA_PORT_FEAT_2_5GB_FD;
        break;

    case SAI_PORT_SPEED_10G:
        portProperties.featuresBmp |= FPA_PORT_FEAT_10GB_FD;
        break;

    case SAI_PORT_SPEED_20G:
        portProperties.featuresBmp |= FPA_PORT_FEAT_20GB_FD;
        break;

    case SAI_PORT_SPEED_25G:
        portProperties.featuresBmp |= FPA_PORT_FEAT_25GB_FD;
        break;

    case SAI_PORT_SPEED_40G:
        portProperties.featuresBmp |= FPA_PORT_FEAT_40GB_FD;
        break;

    case SAI_PORT_SPEED_100G:
        portProperties.featuresBmp |= FPA_PORT_FEAT_100GB_FD;
        break;

    case SAI_PORT_SPEED_1T:
        portProperties.featuresBmp |= FPA_PORT_FEAT_1TB_FD;
        break;

    default:
            MRVL_SAI_LOG_ERR("Unsupported port speed [%d]\n", value->u32);
            return SAI_STATUS_FAILURE;
    }
        
    fpa_status = fpaLibPortPropertiesSet(SAI_DEFAULT_ETH_SWID_CNS,
                                         port_id,
                                         &portProperties);

    if (FPA_OK != fpa_status) {
        MRVL_SAI_LOG_ERR("Failed to set port %d attributes\features (speed)\n",
                         port_id);
        return SAI_STATUS_FAILURE;
    }
  
    MRVL_SAI_LOG_EXIT();
    return SAI_STATUS_SUCCESS;
}

/* Flow Control state [sai_port_flow_control_mode_t] */
sai_status_t mrvl_port_fc_get(_In_ const sai_object_key_t   *key,
                              _Inout_ sai_attribute_value_t *value,
                              _In_ uint32_t                  attr_index,
                              _Inout_ vendor_cache_t        *cache,
                              void                          *arg)
{
    sai_status_t status;
    uint32_t     port_id;

    FPA_STATUS                  fpa_status;
    FPA_PORT_PROPERTIES_STC     portProperties;
        
    MRVL_SAI_LOG_ENTER();

    if (SAI_STATUS_SUCCESS != (status = mrvl_sai_utl_object_to_type(key->key.object_id, SAI_OBJECT_TYPE_PORT, &port_id))) {
        return status;
    }

    portProperties.flags = FPA_PORT_PROPERTIES_FEATURES_FLAG;
        
    fpa_status = fpaLibPortPropertiesGet(SAI_DEFAULT_ETH_SWID_CNS,
                                         port_id,
                                         &portProperties);
    if (FPA_OK != fpa_status) {
        MRVL_SAI_LOG_ERR("Failed to get port %d attributes (fc)\n", port_id);
        return SAI_STATUS_FAILURE;
    }

    switch((FPA_PORT_FEAT_PAUSE | FPA_PORT_FEAT_PAUSE_ASYM) &
                                        portProperties.featuresBmp) {
    case 0:
        value->s32 = SAI_PORT_FLOW_CONTROL_MODE_DISABLE;
        break;

    case (FPA_PORT_FEAT_PAUSE):
        value->s32 = SAI_PORT_FLOW_CONTROL_MODE_BOTH_ENABLE;
        break;

    case (FPA_PORT_FEAT_PAUSE | FPA_PORT_FEAT_PAUSE_ASYM):
        value->s32 = SAI_PORT_FLOW_CONTROL_MODE_RX_ONLY;
        break;

    case (FPA_PORT_FEAT_PAUSE_ASYM):
        value->s32 = SAI_PORT_FLOW_CONTROL_MODE_TX_ONLY;
        break;

    default:
        MRVL_SAI_LOG_ERR("Unreconized port flow control state[0x%x]\n", 
                         portProperties.featuresBmp);
        return SAI_STATUS_FAILURE;
    }

    MRVL_SAI_LOG_EXIT();
    return SAI_STATUS_SUCCESS;
}

/* Flow Control state [sai_port_flow_control_mode_t] */
sai_status_t mrvl_port_fc_set(_In_ const sai_object_key_t      *key, 
                              _In_ const sai_attribute_value_t *value, 
                              void                             *arg)
{
    sai_status_t status;
    uint32_t     port_id;
    
    FPA_STATUS                  fpa_status;
    FPA_PORT_PROPERTIES_STC     portProperties;
        
    MRVL_SAI_LOG_ENTER();

    if (SAI_STATUS_SUCCESS != (status = mrvl_sai_utl_object_to_type(key->key.object_id, SAI_OBJECT_TYPE_PORT, &port_id))) {
        return status;
    }

    /* Get the current port features */
    portProperties.flags = FPA_PORT_PROPERTIES_FEATURES_FLAG;

    fpa_status = fpaLibPortPropertiesGet(SAI_DEFAULT_ETH_SWID_CNS,
                                         port_id,
                                         &portProperties);

    if (FPA_OK != fpa_status) {
        MRVL_SAI_LOG_ERR("Failed to get port %d attributes\features (fc)\n", 
                         port_id);
        return SAI_STATUS_FAILURE;
    }

    portProperties.featuresBmp &= ~(FPA_PORT_FEAT_PAUSE | FPA_PORT_FEAT_PAUSE_ASYM);

    switch(value->s32) {
    case SAI_PORT_FLOW_CONTROL_MODE_DISABLE:
        break;

    case SAI_PORT_FLOW_CONTROL_MODE_TX_ONLY:
        portProperties.featuresBmp |= FPA_PORT_FEAT_PAUSE_ASYM;
        break;

    case SAI_PORT_FLOW_CONTROL_MODE_RX_ONLY:
        portProperties.featuresBmp |= (FPA_PORT_FEAT_PAUSE | FPA_PORT_FEAT_PAUSE_ASYM);
        break;

    case SAI_PORT_FLOW_CONTROL_MODE_BOTH_ENABLE:
        portProperties.featuresBmp |= FPA_PORT_FEAT_PAUSE;
        break;

    default:
            MRVL_SAI_LOG_ERR("Unsupported port fc [%d]\n", value->s32);
            return SAI_STATUS_FAILURE;
    }
        
    fpa_status = fpaLibPortPropertiesSet(SAI_DEFAULT_ETH_SWID_CNS,
                                         port_id,
                                         &portProperties);

    if (FPA_OK != fpa_status) {
        MRVL_SAI_LOG_ERR("Failed to set port %d attributes\features (fc)\n",
                         port_id);
        return SAI_STATUS_FAILURE;
    }
  
    MRVL_SAI_LOG_EXIT();
    return SAI_STATUS_SUCCESS;
}

static sai_status_t mrvl_port_tc_get(_In_ const sai_object_id_t port, _Out_ uint8_t *tc)
{
    MRVL_SAI_LOG_ENTER();

    MRVL_SAI_LOG_EXIT();
    MRVL_SAI_API_RETURN(SAI_STATUS_NOT_IMPLEMENTED);
}

static sai_status_t mrvl_port_ingress_filter_set(_In_ const sai_object_key_t      *key,
                                                 _In_ const sai_attribute_value_t *value,
                                                 void                             *arg)
{
    MRVL_SAI_LOG_ENTER();
    
    MRVL_SAI_LOG_EXIT();
    MRVL_SAI_API_RETURN(SAI_STATUS_NOT_IMPLEMENTED);
}
static sai_status_t mrvl_port_drop_tags_set(_In_ const sai_object_key_t      *key,
                                            _In_ const sai_attribute_value_t *value,
                                            void                             *arg)
{
    MRVL_SAI_LOG_ENTER();
    MRVL_SAI_LOG_EXIT();
    MRVL_SAI_API_RETURN(SAI_STATUS_NOT_IMPLEMENTED);
}
static sai_status_t mrvl_port_internal_loopback_set(_In_ const sai_object_key_t      *key,
                                                    _In_ const sai_attribute_value_t *value,
                                                    void                             *arg)
{
    uint32_t port_id;
    sai_status_t status;

    MRVL_SAI_LOG_ENTER();

    if (SAI_STATUS_SUCCESS != (status = mrvl_sai_utl_object_to_type(key->key.object_id, SAI_OBJECT_TYPE_PORT, &port_id))) {
        return status;
    }


    MRVL_SAI_LOG_EXIT();
    MRVL_SAI_API_RETURN(SAI_STATUS_SUCCESS);
}
static sai_status_t mrvl_port_mtu_set(_In_ const sai_object_key_t      *key,
                                      _In_ const sai_attribute_value_t *value,
                                      void                             *arg)
{
    MRVL_SAI_LOG_ENTER();

    MRVL_SAI_LOG_EXIT();
    MRVL_SAI_API_RETURN(SAI_STATUS_NOT_IMPLEMENTED);
}

static sai_status_t mrvl_port_fec_set(_In_ const sai_object_key_t      *key,
                                      _In_ const sai_attribute_value_t *value,
                                      void                             *arg)
{
    MRVL_SAI_LOG_ENTER();

    MRVL_SAI_LOG_EXIT();
    MRVL_SAI_API_RETURN(SAI_STATUS_NOT_IMPLEMENTED);
}
static sai_status_t mrvl_port_auto_negotiation_set(_In_ const sai_object_key_t      *key,
                                                   _In_ const sai_attribute_value_t *value,
                                                   void                             *arg)
{
    MRVL_SAI_LOG_ENTER();

    MRVL_SAI_LOG_EXIT();
    MRVL_SAI_API_RETURN(SAI_STATUS_NOT_IMPLEMENTED);
}
static sai_status_t mrvl_port_wred_set(_In_ const sai_object_key_t      *key,
                                       _In_ const sai_attribute_value_t *value,
                                       void                             *arg)
{
    MRVL_SAI_LOG_ENTER();

    MRVL_SAI_LOG_EXIT();
    MRVL_SAI_API_RETURN(SAI_STATUS_NOT_IMPLEMENTED);
}
static sai_status_t mrvl_port_type_get(_In_ const sai_object_key_t   *key,
                                       _Inout_ sai_attribute_value_t *value,
                                       _In_ uint32_t                  attr_index,
                                       _Inout_ vendor_cache_t        *cache,
                                       void                          *arg)
{
    MRVL_SAI_LOG_ENTER();

    MRVL_SAI_LOG_EXIT();
    MRVL_SAI_API_RETURN(SAI_STATUS_NOT_IMPLEMENTED);
}

static sai_status_t mrvl_port_supported_breakout_get(_In_ const sai_object_key_t   *key,
                                                     _Inout_ sai_attribute_value_t *value,
                                                     _In_ uint32_t                  attr_index,
                                                     _Inout_ vendor_cache_t        *cache,
                                                     void                          *arg)
{
    MRVL_SAI_LOG_ENTER();

    MRVL_SAI_LOG_EXIT();
    MRVL_SAI_API_RETURN(SAI_STATUS_NOT_IMPLEMENTED);
}
static sai_status_t mrvl_port_current_breakout_get(_In_ const sai_object_key_t   *key,
                                                   _Inout_ sai_attribute_value_t *value,
                                                   _In_ uint32_t                  attr_index,
                                                   _Inout_ vendor_cache_t        *cache,
                                                   void                          *arg)
{
    MRVL_SAI_LOG_ENTER();

    MRVL_SAI_LOG_EXIT();
    MRVL_SAI_API_RETURN(SAI_STATUS_NOT_IMPLEMENTED);
}

static sai_status_t mrvl_port_supported_fec_mode_get(_In_ const sai_object_key_t   *key,
                                                     _Inout_ sai_attribute_value_t *value,
                                                     _In_ uint32_t                  attr_index,
                                                     _Inout_ vendor_cache_t        *cache,
                                                     void                          *arg)
{
    MRVL_SAI_LOG_ENTER();

    MRVL_SAI_LOG_EXIT();
    MRVL_SAI_API_RETURN(SAI_STATUS_NOT_IMPLEMENTED);
}

static sai_status_t mrvl_port_fec_get(_In_ const sai_object_key_t   *key,
                                      _Inout_ sai_attribute_value_t *value,
                                      _In_ uint32_t                  attr_index,
                                      _Inout_ vendor_cache_t        *cache,
                                      void                          *arg)
{
    MRVL_SAI_LOG_ENTER();
    value->s32 = SAI_PORT_FEC_MODE_NONE;
    MRVL_SAI_LOG_EXIT();
    MRVL_SAI_API_RETURN(SAI_STATUS_SUCCESS);
}
static sai_status_t mrvl_port_duplex_get(_In_ const sai_object_key_t   *key,
                                         _Inout_ sai_attribute_value_t *value,
                                         _In_ uint32_t                  attr_index,
                                         _Inout_ vendor_cache_t        *cache,
                                         void                          *arg)
{
    MRVL_SAI_LOG_ENTER();
    value->booldata = true;
    MRVL_SAI_LOG_EXIT();
    MRVL_SAI_API_RETURN(SAI_STATUS_SUCCESS);
}
static sai_status_t mrvl_port_auto_negotiation_get(_In_ const sai_object_key_t   *key,
                                                   _Inout_ sai_attribute_value_t *value,
                                                   _In_ uint32_t                  attr_index,
                                                   _Inout_ vendor_cache_t        *cache,
                                                   void                          *arg)
{
    MRVL_SAI_LOG_ENTER();

    MRVL_SAI_LOG_EXIT();
    MRVL_SAI_API_RETURN(SAI_STATUS_NOT_IMPLEMENTED);
}

static sai_status_t mrvl_port_ingress_filter_get(_In_ const sai_object_key_t   *key,
                                                 _Inout_ sai_attribute_value_t *value,
                                                 _In_ uint32_t                  attr_index,
                                                 _Inout_ vendor_cache_t        *cache,
                                                 void                          *arg)
{
    MRVL_SAI_LOG_ENTER();
    value->booldata = false;
    MRVL_SAI_LOG_EXIT();
    MRVL_SAI_API_RETURN(SAI_STATUS_SUCCESS);
}
static sai_status_t mrvl_port_drop_tags_get(_In_ const sai_object_key_t   *key,
                                            _Inout_ sai_attribute_value_t *value,
                                            _In_ uint32_t                  attr_index,
                                            _Inout_ vendor_cache_t        *cache,
                                            void                          *arg)
{
    MRVL_SAI_LOG_ENTER();
    value->booldata = false;

    MRVL_SAI_LOG_EXIT();
    MRVL_SAI_API_RETURN(SAI_STATUS_SUCCESS);
}
static sai_status_t mrvl_port_internal_loopback_get(_In_ const sai_object_key_t   *key,
                                                    _Inout_ sai_attribute_value_t *value,
                                                    _In_ uint32_t                  attr_index,
                                                    _Inout_ vendor_cache_t        *cache,
                                                    void                          *arg)
{
    MRVL_SAI_LOG_ENTER();
    value->s32 = SAI_PORT_INTERNAL_LOOPBACK_MODE_NONE;
    MRVL_SAI_LOG_EXIT();
    MRVL_SAI_API_RETURN(SAI_STATUS_SUCCESS);
}
static sai_status_t mrvl_port_mtu_get(_In_ const sai_object_key_t   *key,
                                      _Inout_ sai_attribute_value_t *value,
                                      _In_ uint32_t                  attr_index,
                                      _Inout_ vendor_cache_t        *cache,
                                      void                          *arg)
{
    MRVL_SAI_LOG_ENTER();
    value->u32 = 1514; /*default*/
    MRVL_SAI_LOG_EXIT();
    MRVL_SAI_API_RETURN(SAI_STATUS_SUCCESS);
}

static sai_status_t mrvl_port_wred_get(_In_ const sai_object_key_t   *key,
                                       _Inout_ sai_attribute_value_t *value,
                                       _In_ uint32_t                  attr_index,
                                       _Inout_ vendor_cache_t        *cache,
                                       void                          *arg)
{
    MRVL_SAI_LOG_ENTER();
    value->oid = SAI_NULL_OBJECT_ID;
    MRVL_SAI_LOG_EXIT();
    MRVL_SAI_API_RETURN(SAI_STATUS_SUCCESS);
}
static sai_status_t mrvl_port_update_dscp_get(_In_ const sai_object_key_t   *key,
                                              _Inout_ sai_attribute_value_t *value,
                                              _In_ uint32_t                  attr_index,
                                              _Inout_ vendor_cache_t        *cache,
                                              void                          *arg)
{
    MRVL_SAI_LOG_ENTER();
    value->booldata = false;
    MRVL_SAI_LOG_EXIT();
    MRVL_SAI_API_RETURN(SAI_STATUS_SUCCESS);
}
static sai_status_t mrvl_port_update_dscp_set(_In_ const sai_object_key_t      *key,
                                              _In_ const sai_attribute_value_t *value,
                                              void                             *arg)
{
    MRVL_SAI_LOG_ENTER();

    MRVL_SAI_LOG_EXIT();
    MRVL_SAI_API_RETURN(SAI_STATUS_NOT_IMPLEMENTED);
}
static sai_status_t mrvl_port_qos_default_tc_get(_In_ const sai_object_key_t   *key,
                                                 _Inout_ sai_attribute_value_t *value,
                                                 _In_ uint32_t                  attr_index,
                                                 _Inout_ vendor_cache_t        *cache,
                                                 void                          *arg)
{
    MRVL_SAI_LOG_ENTER();
    value->u8 = 0;
    MRVL_SAI_LOG_EXIT();
    MRVL_SAI_API_RETURN(SAI_STATUS_SUCCESS);
}
static sai_status_t mrvl_port_qos_default_tc_set(_In_ const sai_object_key_t      *key,
                                                 _In_ const sai_attribute_value_t *value,
                                                 void                             *arg)
{
    MRVL_SAI_LOG_ENTER();

    MRVL_SAI_LOG_EXIT();
    MRVL_SAI_API_RETURN(SAI_STATUS_NOT_IMPLEMENTED);
}
static sai_status_t mrvl_port_qos_map_id_get(_In_ const sai_object_key_t   *key,
                                             _Inout_ sai_attribute_value_t *value,
                                             _In_ uint32_t                  attr_index,
                                             _Inout_ vendor_cache_t        *cache,
                                             void                          *arg)
{
    MRVL_SAI_LOG_ENTER();
    value->oid = SAI_NULL_OBJECT_ID;
    MRVL_SAI_LOG_EXIT();
    MRVL_SAI_API_RETURN(SAI_STATUS_SUCCESS);
}
static sai_status_t mrvl_port_qos_map_id_set(_In_ const sai_object_key_t      *key,
                                             _In_ const sai_attribute_value_t *value,
                                             void                             *arg)
{
    MRVL_SAI_LOG_ENTER();

    MRVL_SAI_LOG_EXIT();
    MRVL_SAI_API_RETURN(SAI_STATUS_NOT_IMPLEMENTED);
}
static sai_status_t mrvl_port_mirror_session_get(_In_ const sai_object_key_t   *key,
                                                 _Inout_ sai_attribute_value_t *value,
                                                 _In_ uint32_t                  attr_index,
                                                 _Inout_ vendor_cache_t        *cache,
                                                 void                          *arg)
{
    sai_status_t status;
    sai_object_id_t data_obj;

    MRVL_SAI_LOG_ENTER();
    /* create SAI mirror session object */    
    if (SAI_STATUS_SUCCESS != (status = mrvl_sai_utl_create_object(SAI_OBJECT_TYPE_MIRROR_SESSION, 1, &data_obj))) {
        MRVL_SAI_API_RETURN(status);
    }

    /* fill object list for SAI_OBJECT_TYPE_MIRROR_SESSION */
    if (SAI_STATUS_SUCCESS != (status = mrvl_sai_utl_fill_objlist(&data_obj ,1, &value->objlist))) {
        MRVL_SAI_LOG_ERR("Failed to fill objlist for SAI_OBJECT_TYPE_MIRROR_SESSION\n");
        MRVL_SAI_API_RETURN(status);
    }

    MRVL_SAI_LOG_EXIT();
    MRVL_SAI_API_RETURN(SAI_STATUS_SUCCESS);
}
static sai_status_t mrvl_port_mirror_session_set(_In_ const sai_object_key_t      *key,
                                                 _In_ const sai_attribute_value_t *value,
                                                 void                             *arg)
{
    MRVL_SAI_LOG_ENTER();

    MRVL_SAI_LOG_EXIT();
    MRVL_SAI_API_RETURN(SAI_STATUS_NOT_IMPLEMENTED);
}
static sai_status_t mrvl_port_samplepacket_session_get(_In_ const sai_object_key_t   *key,
                                                       _Inout_ sai_attribute_value_t *value,
                                                       _In_ uint32_t                  attr_index,
                                                       _Inout_ vendor_cache_t        *cache,
                                                       void                          *arg)
{
    MRVL_SAI_LOG_ENTER();
    value->oid = SAI_NULL_OBJECT_ID;
    MRVL_SAI_LOG_EXIT();
    MRVL_SAI_API_RETURN(SAI_STATUS_SUCCESS);
}
static sai_status_t mrvl_port_samplepacket_session_set(_In_ const sai_object_key_t      *key,
                                                       _In_ const sai_attribute_value_t *value,
                                                       void                             *arg)
{
    MRVL_SAI_LOG_ENTER();

    MRVL_SAI_LOG_EXIT();
    MRVL_SAI_API_RETURN(SAI_STATUS_NOT_IMPLEMENTED);
}
static sai_status_t mrvl_port_pfc_control_get(_In_ const sai_object_key_t   *key,
                                              _Inout_ sai_attribute_value_t *value,
                                              _In_ uint32_t                  attr_index,
                                              _Inout_ vendor_cache_t        *cache,
                                              void                          *arg)
{
    MRVL_SAI_LOG_ENTER();
    value->u8 = 0;
    MRVL_SAI_LOG_EXIT();
    MRVL_SAI_API_RETURN(SAI_STATUS_SUCCESS);
}
static sai_status_t mrvl_port_pfc_control_set(_In_ const sai_object_key_t      *key,
                                              _In_ const sai_attribute_value_t *value,
                                              void                             *arg)
{
    MRVL_SAI_LOG_ENTER();

    MRVL_SAI_LOG_EXIT();
    MRVL_SAI_API_RETURN(SAI_STATUS_NOT_IMPLEMENTED);
}
static sai_status_t mrvl_port_sched_get(_In_ const sai_object_key_t   *key,
                                        _Inout_ sai_attribute_value_t *value,
                                        _In_ uint32_t                  attr_index,
                                        _Inout_ vendor_cache_t        *cache,
                                        void                          *arg)
{
    MRVL_SAI_LOG_ENTER();
    value->oid = SAI_NULL_OBJECT_ID;
    MRVL_SAI_LOG_EXIT();
    MRVL_SAI_API_RETURN(SAI_STATUS_SUCCESS);
}
static sai_status_t mrvl_port_sched_set(_In_ const sai_object_key_t      *key,
                                        _In_ const sai_attribute_value_t *value,
                                        void                             *arg)
{
    MRVL_SAI_LOG_ENTER();

    MRVL_SAI_LOG_EXIT();
    MRVL_SAI_API_RETURN(SAI_STATUS_NOT_IMPLEMENTED);
}
static sai_status_t mrvl_port_ingress_buffer_profile_list_get(_In_ const sai_object_key_t   *key,
                                                              _Inout_ sai_attribute_value_t *value,
                                                              _In_ uint32_t                  attr_index,
                                                              _Inout_ vendor_cache_t        *cache,
                                                              void                          *arg)
{
    
    sai_status_t status;
    sai_object_id_t data_obj;

    MRVL_SAI_LOG_ENTER();
    /* create SAI buffer profile object */    
    if (SAI_STATUS_SUCCESS != (status = mrvl_sai_utl_create_object(SAI_OBJECT_TYPE_BUFFER_PROFILE, 1, &data_obj))) {
        MRVL_SAI_API_RETURN(status);
    }

    /* fill object list for SAI_OBJECT_TYPE_BUFFER_PROFILE */
    if (SAI_STATUS_SUCCESS != (status = mrvl_sai_utl_fill_objlist(&data_obj ,1, &value->objlist))) {
        MRVL_SAI_LOG_ERR("Failed to fill objlist for SAI_OBJECT_TYPE_BUFFER_PROFILE\n");
        MRVL_SAI_API_RETURN(status);
    }

    MRVL_SAI_LOG_EXIT();
    MRVL_SAI_API_RETURN(SAI_STATUS_SUCCESS);
}
static sai_status_t mrvl_port_ingress_buffer_profile_list_set(_In_ const sai_object_key_t      *key,
                                                              _In_ const sai_attribute_value_t *value,
                                                              void                             *arg)
{
    MRVL_SAI_LOG_ENTER();

    MRVL_SAI_LOG_EXIT();
    MRVL_SAI_API_RETURN(SAI_STATUS_NOT_IMPLEMENTED);
}
static sai_status_t mrvl_port_egress_buffer_profile_list_get(_In_ const sai_object_key_t   *key,
                                                             _Inout_ sai_attribute_value_t *value,
                                                             _In_ uint32_t                  attr_index,
                                                             _Inout_ vendor_cache_t        *cache,
                                                             void                          *arg)
{
    sai_object_id_t data_obj;
    sai_status_t status;

    MRVL_SAI_LOG_ENTER();
    /* create SAI buffer profile object */    
    if (SAI_STATUS_SUCCESS != (status = mrvl_sai_utl_create_object(SAI_OBJECT_TYPE_BUFFER_PROFILE, 1, &data_obj))) {
        MRVL_SAI_API_RETURN(status);
    }

    /* fill object list for SAI_OBJECT_TYPE_BUFFER_PROFILE */
    if (SAI_STATUS_SUCCESS != (status = mrvl_sai_utl_fill_objlist(&data_obj ,1, &value->objlist))) {
        MRVL_SAI_LOG_ERR("Failed to fill objlist for SAI_OBJECT_TYPE_BUFFER_PROFILE\n");
        MRVL_SAI_API_RETURN(status);
    }

    MRVL_SAI_LOG_EXIT();
    MRVL_SAI_API_RETURN(SAI_STATUS_SUCCESS);
}
static sai_status_t mrvl_port_egress_buffer_profile_list_set(_In_ const sai_object_key_t      *key,
                                                             _In_ const sai_attribute_value_t *value,
                                                             void                             *arg)
{
    MRVL_SAI_LOG_ENTER();

    MRVL_SAI_LOG_EXIT();
    MRVL_SAI_API_RETURN(SAI_STATUS_NOT_IMPLEMENTED);
}
static sai_status_t mrvl_port_storm_control_policer_attr_set(_In_ const sai_object_key_t      *key,
                                                             _In_ const sai_attribute_value_t *value,
                                                             _In_ void                        *arg)
{
    MRVL_SAI_LOG_ENTER();

    MRVL_SAI_LOG_EXIT();
    MRVL_SAI_API_RETURN(SAI_STATUS_NOT_IMPLEMENTED);
}
static sai_status_t mrvl_port_storm_control_policer_attr_get(_In_ const sai_object_key_t   *key,
                                                             _Inout_ sai_attribute_value_t *value,
                                                             _In_ uint32_t                  attr_index,
                                                             _Inout_ vendor_cache_t        *cache,
                                                             _In_ void                     *arg)
{
    
    MRVL_SAI_LOG_ENTER();
    sai_status_t status;
    uint32_t port_id;

    MRVL_SAI_LOG_ENTER();

    status = mrvl_sai_utl_object_to_type(key->key.object_id, SAI_OBJECT_TYPE_PORT, &port_id);
    if (status != SAI_STATUS_SUCCESS) {
        return status;
    }
    
    if (CPU_PORT == port_id)
    {
        MRVL_SAI_LOG_NTC("Port %d is CPU port. Returning NULL object id\n");
        value->oid = SAI_NULL_OBJECT_ID;
    }
    else
    {
        /* create SAI policer object */    
        if (SAI_STATUS_SUCCESS != (status = mrvl_sai_utl_create_object(SAI_OBJECT_TYPE_POLICER, 1, &value->oid))) {
            MRVL_SAI_API_RETURN(status);
        }
    }
    MRVL_SAI_LOG_EXIT();
    MRVL_SAI_API_RETURN(SAI_STATUS_SUCCESS);
}
static sai_status_t mrvl_port_bind_mode_set(_In_ const sai_object_key_t      *key,
                                            _In_ const sai_attribute_value_t *value,
                                            _In_ void                        *arg)
{
    MRVL_SAI_LOG_ENTER();

    MRVL_SAI_LOG_EXIT();
    MRVL_SAI_API_RETURN(SAI_STATUS_NOT_IMPLEMENTED);
}
static sai_status_t mrvl_port_bind_mode_get(_In_ const sai_object_key_t   *key,
                                            _Inout_ sai_attribute_value_t *value,
                                            _In_ uint32_t                  attr_index,
                                            _Inout_ vendor_cache_t        *cache,
                                            _In_ void                     *arg)
{
    MRVL_SAI_LOG_ENTER();
    value->s32 = SAI_PORT_BIND_MODE_PORT;
    MRVL_SAI_LOG_EXIT();
    MRVL_SAI_API_RETURN(SAI_STATUS_SUCCESS);
}
static sai_status_t mrvl_port_egress_block_set(_In_ const sai_object_key_t      *key,
                                               _In_ const sai_attribute_value_t *value,
                                               _In_ void                        *arg)
{
    MRVL_SAI_LOG_ENTER();

    MRVL_SAI_LOG_EXIT();
    MRVL_SAI_API_RETURN(SAI_STATUS_NOT_IMPLEMENTED);
}
static sai_status_t mrvl_port_egress_block_get(_In_ const sai_object_key_t   *key,
                                               _Inout_ sai_attribute_value_t *value,
                                               _In_ uint32_t                  attr_index,
                                               _Inout_ vendor_cache_t        *cache,
                                               _In_ void                     *arg)
{
    sai_object_id_t data_obj;
    sai_status_t status;

    MRVL_SAI_LOG_ENTER();
    /* create SAI port object */    
    if (SAI_STATUS_SUCCESS != (status = mrvl_sai_utl_create_object(SAI_OBJECT_TYPE_PORT, 1, &data_obj))) {
        MRVL_SAI_API_RETURN(status);
    }

    /* fill object list for SAI_OBJECT_TYPE_PORT */
    if (SAI_STATUS_SUCCESS != (status = mrvl_sai_utl_fill_objlist(&data_obj ,1, &value->objlist))) {
        MRVL_SAI_LOG_ERR("Failed to fill objlist for SAI_OBJECT_TYPE_PORT\n");
        MRVL_SAI_API_RETURN(status);
    }

    MRVL_SAI_LOG_EXIT();
    MRVL_SAI_API_RETURN(SAI_STATUS_SUCCESS);
}

static void port_key_to_str(_In_ sai_object_id_t port_id, _Out_ char *key_str)
{
    uint32_t port;

    if (SAI_STATUS_SUCCESS != mrvl_sai_utl_object_to_type(port_id, SAI_OBJECT_TYPE_PORT, &port)) {
        snprintf(key_str, MAX_KEY_STR_LEN, "invalid port");
    } else {
        snprintf(key_str, MAX_KEY_STR_LEN, "port %x", port);
    }
}

/**
 * @brief Set port attribute value.
 *
 * @param[in] port_id Port id
 * @param[in] attr Attribute
 *
 * @return #SAI_STATUS_SUCCESS on success Failure status code on error



 */

sai_status_t mrvl_set_port_attribute(_In_ sai_object_id_t port_id, _In_ const sai_attribute_t *attr)
{
    const sai_object_key_t key = { .key.object_id = port_id };
    char                   key_str[MAX_KEY_STR_LEN];
    sai_status_t status;

    MRVL_SAI_LOG_ENTER();

    port_key_to_str(port_id, key_str);
    status = mrvl_sai_utl_set_attribute(&key, key_str, port_attribs, port_vendor_attribs, attr);
    MRVL_SAI_API_RETURN(status);
}

/**



 * @brief Get port attribute value.
 *
 * @param[in] port_id Port id
 * @param[in] attr_count Number of attributes
 * @param[inout] attr_list Array of attributes
 *
 * @return #SAI_STATUS_SUCCESS on success Failure status code on error



 */
sai_status_t mrvl_get_port_attribute(_In_ sai_object_id_t     port_id,
                                     _In_ uint32_t            attr_count,
                                     _Inout_ sai_attribute_t *attr_list)
{
    const sai_object_key_t key = { .key.object_id = port_id };
    char                   key_str[MAX_KEY_STR_LEN];
    sai_status_t status;

    MRVL_SAI_LOG_ENTER();

    port_key_to_str(port_id, key_str);
    status = mrvl_sai_utl_get_attributes(&key, key_str, port_attribs, port_vendor_attribs, attr_count, attr_list);
    MRVL_SAI_API_RETURN(status);
}

/**


 * @brief Get port statistics counters.
 *
 * @param[in] port_id Port id
 * @param[in] number_of_counters Number of counters in the array
 * @param[in] counter_ids Specifies the array of counter ids
 * @param[out] counters Array of resulting counter values.
 *
 * @return #SAI_STATUS_SUCCESS on success Failure status code on error



 */

sai_status_t mrvl_get_port_stats(_In_ sai_object_id_t                port_id,
                                 _In_ uint32_t                       number_of_counters,
                                 _In_ const sai_port_stat_t         *counter_ids,
                                 _Out_ uint64_t                     *counters)
{
    sai_status_t status;
    uint32_t     ii, port;
    char         key_str[MAX_KEY_STR_LEN];

    FPA_STATUS   fpa_status;
    FPA_PORT_COUNTERS_EXT_STC   port_ext_statistics;

    MRVL_SAI_LOG_ENTER();

    port_key_to_str(port_id, key_str);
    MRVL_SAI_LOG_NTC("Get port stats %s\n", key_str);

    if (NULL == counter_ids) {
        MRVL_SAI_LOG_ERR("NULL counter ids array param\n");
        MRVL_SAI_API_RETURN(SAI_STATUS_INVALID_PARAMETER);
    }

    if (NULL == counters) {
        MRVL_SAI_LOG_ERR("NULL counters array param\n");
        MRVL_SAI_API_RETURN(SAI_STATUS_INVALID_PARAMETER);
    }

    if (0 == number_of_counters) {
        MRVL_SAI_LOG_WRN("0 (ZERO) counters requested\n");
        MRVL_SAI_API_RETURN(SAI_STATUS_SUCCESS);
    }

    if (SAI_STATUS_SUCCESS != (status = mrvl_sai_utl_object_to_type(port_id, SAI_OBJECT_TYPE_PORT, &port))) {
    	MRVL_SAI_API_RETURN(status);
    }

    fpa_status = fpaLibPortStatisticsExtGet(SAI_DEFAULT_ETH_SWID_CNS, 
                                            port, 
                                            &port_ext_statistics);

    if (FPA_OK != fpa_status) {
        MRVL_SAI_LOG_ERR("Failed to get port %d extended counters\n", port);
/*        return SAI_STATUS_FAILURE;*/
        status = mrvl_sai_utl_fpa_to_sai_status(fpa_status);
        MRVL_SAI_API_RETURN(status);
    }

    for (ii = 0; ii < number_of_counters; ii++) {
        switch (counter_ids[ii]) {
        case SAI_PORT_STAT_IF_IN_OCTETS:
            counters[ii] = port_ext_statistics.goodOctetsReceived +
                            port_ext_statistics.badOctetsReceived;
            break;

        case SAI_PORT_STAT_IF_IN_UCAST_PKTS:
            counters[ii] = port_ext_statistics.goodUnicastFramesReceived;
            break;

        case SAI_PORT_STAT_IF_IN_NON_UCAST_PKTS:
            counters[ii] = port_ext_statistics.multicastFramesReceived + 
                            port_ext_statistics.broadcastFramesReceived;
            break;

        case SAI_PORT_STAT_IF_IN_ERRORS:
            counters[ii] = port_ext_statistics.rxErrorFrameReceived;
            break;

        case SAI_PORT_STAT_IF_IN_BROADCAST_PKTS:
            counters[ii] = port_ext_statistics.broadcastFramesReceived;
            break;

        case SAI_PORT_STAT_IF_IN_MULTICAST_PKTS:
            counters[ii] = port_ext_statistics.multicastFramesReceived;
            break;

        case SAI_PORT_STAT_IF_OUT_OCTETS:
            counters[ii] = port_ext_statistics.goodOctetsSent;
            break;

        case SAI_PORT_STAT_IF_OUT_UCAST_PKTS:
            counters[ii] = port_ext_statistics.unicastFrameSent;
            break;

        case SAI_PORT_STAT_IF_OUT_NON_UCAST_PKTS:
            counters[ii] = port_ext_statistics.multicastFramesSent +
                            port_ext_statistics.broadcastFramesSent;
            break;

        case SAI_PORT_STAT_IF_OUT_BROADCAST_PKTS:
            counters[ii] = port_ext_statistics.broadcastFramesSent;
            break;

        case SAI_PORT_STAT_IF_OUT_MULTICAST_PKTS:
            counters[ii] = port_ext_statistics.multicastFramesSent;
            break;

        case SAI_PORT_STAT_ETHER_STATS_DROP_EVENTS:
            counters[ii] = port_ext_statistics.receiveFIFOoverrun;
            break;

        case SAI_PORT_STAT_ETHER_STATS_MULTICAST_PKTS:
            counters[ii] = port_ext_statistics.multicastFramesReceived;
            break;

        case SAI_PORT_STAT_ETHER_STATS_BROADCAST_PKTS:
            counters[ii] = port_ext_statistics.broadcastFramesReceived;
            break;

        case SAI_PORT_STAT_ETHER_STATS_UNDERSIZE_PKTS:
            counters[ii] = port_ext_statistics.undersizePktsRecieved;
            break;

        case SAI_PORT_STAT_ETHER_STATS_FRAGMENTS:
            counters[ii] = port_ext_statistics.fragmentsRecieved;
            break;

        case SAI_PORT_STAT_ETHER_STATS_PKTS_64_OCTETS:
            counters[ii] = port_ext_statistics.rxFrames64Octets;
            break;

        case SAI_PORT_STAT_ETHER_STATS_PKTS_65_TO_127_OCTETS:
            counters[ii] = port_ext_statistics.rxFrames65to127Octets;
            break;

        case SAI_PORT_STAT_ETHER_STATS_PKTS_128_TO_255_OCTETS:
            counters[ii] = port_ext_statistics.rxFrames128to255Octets;
            break;

        case SAI_PORT_STAT_ETHER_STATS_PKTS_256_TO_511_OCTETS:
            counters[ii] = port_ext_statistics.rxFrames256to511Octets;
            break;

        case SAI_PORT_STAT_ETHER_STATS_PKTS_512_TO_1023_OCTETS:
            counters[ii] = port_ext_statistics.rxFrames512to1023Octets;
            break;

        case SAI_PORT_STAT_ETHER_STATS_PKTS_1024_TO_1518_OCTETS:
            counters[ii] = port_ext_statistics.rxFrames1024to1518Octets;
            break;

        case SAI_PORT_STAT_ETHER_STATS_OVERSIZE_PKTS:
            counters[ii] = port_ext_statistics.oversizePktsRecieved;
            break;

        case SAI_PORT_STAT_ETHER_RX_OVERSIZE_PKTS:
            counters[ii] = port_ext_statistics.oversizePktsRecieved;
            break;

        case SAI_PORT_STAT_ETHER_STATS_JABBERS:
            counters[ii] = port_ext_statistics.rxJabberPksRecieved;
            break;

        case SAI_PORT_STAT_ETHER_STATS_COLLISIONS:
            counters[ii] = port_ext_statistics.collisions;
            break;

        case SAI_PORT_STAT_ETHER_STATS_CRC_ALIGN_ERRORS:
            counters[ii] = port_ext_statistics.badCRC;
            break;

        case SAI_PORT_STAT_ETHER_IN_PKTS_64_OCTETS:
            counters[ii] = port_ext_statistics.rxFrames64Octets;
            break;

        case SAI_PORT_STAT_ETHER_IN_PKTS_65_TO_127_OCTETS:
            counters[ii] = port_ext_statistics.rxFrames65to127Octets;
            break;

        case SAI_PORT_STAT_ETHER_IN_PKTS_128_TO_255_OCTETS:
            counters[ii] = port_ext_statistics.rxFrames128to255Octets;
            break;

        case SAI_PORT_STAT_ETHER_IN_PKTS_256_TO_511_OCTETS:
            counters[ii] = port_ext_statistics.rxFrames256to511Octets;
            break;

        case SAI_PORT_STAT_ETHER_IN_PKTS_512_TO_1023_OCTETS:
            counters[ii] = port_ext_statistics.rxFrames512to1023Octets;
            break;

        case SAI_PORT_STAT_ETHER_IN_PKTS_1024_TO_1518_OCTETS:
            counters[ii] = port_ext_statistics.rxFrames1024to1518Octets;
            break;
        
        case SAI_PORT_STAT_IF_IN_DISCARDS:
        case SAI_PORT_STAT_IF_IN_UNKNOWN_PROTOS:
        case SAI_PORT_STAT_IF_IN_VLAN_DISCARDS:
        case SAI_PORT_STAT_IF_OUT_DISCARDS:
        case SAI_PORT_STAT_IF_OUT_ERRORS:
        case SAI_PORT_STAT_IF_OUT_QLEN:
        case SAI_PORT_STAT_ETHER_STATS_OCTETS:
        case SAI_PORT_STAT_ETHER_STATS_PKTS:
        case SAI_PORT_STAT_ETHER_TX_OVERSIZE_PKTS:
        case SAI_PORT_STAT_ETHER_STATS_TX_NO_ERRORS:
        case SAI_PORT_STAT_ETHER_STATS_RX_NO_ERRORS:
        case SAI_PORT_STAT_ETHER_STATS_PKTS_1519_TO_2047_OCTETS:
        case SAI_PORT_STAT_ETHER_STATS_PKTS_2048_TO_4095_OCTETS:
        case SAI_PORT_STAT_ETHER_STATS_PKTS_4096_TO_9216_OCTETS:
        case SAI_PORT_STAT_ETHER_STATS_PKTS_9217_TO_16383_OCTETS:
        case SAI_PORT_STAT_IP_IN_RECEIVES:
        case SAI_PORT_STAT_IP_IN_OCTETS:
        case SAI_PORT_STAT_IP_IN_UCAST_PKTS:
        case SAI_PORT_STAT_IP_IN_NON_UCAST_PKTS:
        case SAI_PORT_STAT_IP_IN_DISCARDS:
        case SAI_PORT_STAT_IP_OUT_OCTETS:
        case SAI_PORT_STAT_IP_OUT_UCAST_PKTS:
        case SAI_PORT_STAT_IP_OUT_NON_UCAST_PKTS:
        case SAI_PORT_STAT_IP_OUT_DISCARDS:
        case SAI_PORT_STAT_IPV6_IN_RECEIVES:
        case SAI_PORT_STAT_IPV6_IN_OCTETS:
        case SAI_PORT_STAT_IPV6_IN_UCAST_PKTS:
        case SAI_PORT_STAT_IPV6_IN_NON_UCAST_PKTS:
        case SAI_PORT_STAT_IPV6_IN_MCAST_PKTS:
        case SAI_PORT_STAT_IPV6_IN_DISCARDS:
        case SAI_PORT_STAT_IPV6_OUT_OCTETS:
        case SAI_PORT_STAT_IPV6_OUT_UCAST_PKTS:
        case SAI_PORT_STAT_IPV6_OUT_NON_UCAST_PKTS:
        case SAI_PORT_STAT_IPV6_OUT_MCAST_PKTS:
        case SAI_PORT_STAT_IPV6_OUT_DISCARDS:
        case SAI_PORT_STAT_GREEN_DISCARD_DROPPED_PACKETS:
        case SAI_PORT_STAT_GREEN_DISCARD_DROPPED_BYTES:
        case SAI_PORT_STAT_YELLOW_DISCARD_DROPPED_PACKETS:
        case SAI_PORT_STAT_YELLOW_DISCARD_DROPPED_BYTES:
        case SAI_PORT_STAT_RED_DISCARD_DROPPED_PACKETS:
        case SAI_PORT_STAT_RED_DISCARD_DROPPED_BYTES:
        case SAI_PORT_STAT_DISCARD_DROPPED_PACKETS:
        case SAI_PORT_STAT_DISCARD_DROPPED_BYTES:
        case SAI_PORT_STAT_ECN_MARKED_PACKETS:
        case SAI_PORT_STAT_ETHER_IN_PKTS_1519_TO_2047_OCTETS:
        case SAI_PORT_STAT_ETHER_IN_PKTS_2048_TO_4095_OCTETS:
        case SAI_PORT_STAT_ETHER_IN_PKTS_4096_TO_9216_OCTETS:
        case SAI_PORT_STAT_ETHER_IN_PKTS_9217_TO_16383_OCTETS:  
        case SAI_PORT_STAT_ETHER_OUT_PKTS_64_OCTETS:
        case SAI_PORT_STAT_ETHER_OUT_PKTS_65_TO_127_OCTETS:
        case SAI_PORT_STAT_ETHER_OUT_PKTS_128_TO_255_OCTETS:
        case SAI_PORT_STAT_ETHER_OUT_PKTS_256_TO_511_OCTETS:
        case SAI_PORT_STAT_ETHER_OUT_PKTS_512_TO_1023_OCTETS:
        case SAI_PORT_STAT_ETHER_OUT_PKTS_1024_TO_1518_OCTETS:
        case SAI_PORT_STAT_ETHER_OUT_PKTS_1519_TO_2047_OCTETS:
        case SAI_PORT_STAT_ETHER_OUT_PKTS_2048_TO_4095_OCTETS:
        case SAI_PORT_STAT_ETHER_OUT_PKTS_4096_TO_9216_OCTETS:
        case SAI_PORT_STAT_ETHER_OUT_PKTS_9217_TO_16383_OCTETS:
            counters[ii] = 0;
            break;

        default:
            MRVL_SAI_LOG_ERR("Invalid port counter %d\n", counter_ids[ii]);
            counters[ii] = 0;
        }
    }

    MRVL_SAI_LOG_EXIT();

    MRVL_SAI_API_RETURN(SAI_STATUS_SUCCESS);
}


/**
 * @brief Clear port's all statistics counters.
 *
 * @param[in] port_id Port id
 *
 * @return #SAI_STATUS_SUCCESS on success Failure status code on error
 */

sai_status_t mrvl_clear_port_all_stats(_In_ sai_object_id_t port_id)
{
    sai_status_t status;
    uint32_t     port;
    char         key_str[MAX_KEY_STR_LEN];

    FPA_STATUS   fpa_status;

    MRVL_SAI_LOG_ENTER();

    port_key_to_str(port_id, key_str);
    MRVL_SAI_LOG_NTC("Clear port stats %s\n", key_str);

    if (SAI_STATUS_SUCCESS != (status = mrvl_sai_utl_object_to_type(port_id, SAI_OBJECT_TYPE_PORT, &port))) {
    	MRVL_SAI_API_RETURN(status);
    }

    fpa_status = fpaLibPortStatisticsClear(SAI_DEFAULT_ETH_SWID_CNS, port);

    if (FPA_OK != fpa_status) {
        MRVL_SAI_LOG_ERR("Failed to clear port %d counters\n", port);
/*        return SAI_STATUS_FAILURE;*/
        status = mrvl_sai_utl_fpa_to_sai_status(fpa_status);
        MRVL_SAI_API_RETURN(status);
    }

    MRVL_SAI_LOG_EXIT();
    MRVL_SAI_API_RETURN(SAI_STATUS_SUCCESS);
}

#if 0
TODO probably must move to fdb apis
/* FDB Learning mode [sai_port_fdb_learning_mode_t] */
sai_status_t mrvl_port_fdb_learning_get(_In_ const sai_object_key_t   *key,
                                        _Inout_ sai_attribute_value_t *value,
                                        _In_ uint32_t                  attr_index,
                                        _Inout_ vendor_cache_t        *cache,
                                        void                          *arg)
{
    sai_status_t status;
    uint32_t     port_id;

    FPA_STATUS                      fpa_status;
    FPA_SRCMAC_LEARNING_MODE_ENT    learn_mode;
    
        
    MRVL_SAI_LOG_ENTER();

    if (SAI_STATUS_SUCCESS != (status = mrvl_sai_utl_object_to_type(key->key.object_id, SAI_OBJECT_TYPE_PORT, &port_id))) {
        return status;
    }

    fpa_status = fpaLibPortSrcMacLearningGet(SAI_DEFAULT_ETH_SWID_CNS, 
                                             port_id, 
                                             &learn_mode);

    if (FPA_OK != fpa_status) {
        MRVL_SAI_LOG_ERR("Failed to get port %d MAC learning mode\n", port_id);
        return SAI_STATUS_FAILURE;
    }

    switch(learn_mode) {
    case FPA_SRCMAC_LEARNING_FRWD_NONE_E:
        value->s32 = SAI_PORT_LEARN_MODE_DISABLE;
        break;

    case FPA_SRCMAC_LEARNING_DROP_NONE_E:
        value->s32 = SAI_PORT_LEARN_MODE_DROP;
        break;

    case FPA_SRCMAC_LEARNING_FRWD_CTRL_E:
        value->s32 = SAI_PORT_LEARN_MODE_CPU_LOG;
        break;

    case FPA_SRCMAC_LEARNING_DROP_CTRL_E:
        value->s32 = SAI_PORT_LEARN_MODE_CPU_TRAP;
        break;

    case FPA_SRCMAC_LEARNING_AUTO_E:
        value->s32 = SAI_PORT_LEARN_MODE_HW;
        break;

    default:
        MRVL_SAI_LOG_ERR("Unknown port %d MAC learning mode %d\n",
                         port_id, learn_mode);
        return SAI_STATUS_FAILURE;
    }

    MRVL_SAI_LOG_EXIT();
    return SAI_STATUS_SUCCESS;
}

/* FDB Learning mode [sai_port_fdb_learning_mode_t] */
sai_status_t mrvl_port_fdb_learning_set(_In_ const sai_object_key_t      *key,
                                        _In_ const sai_attribute_value_t *value,
                                        void                             *arg)
{
    sai_status_t status;
    uint32_t     port_id;

    FPA_STATUS                      fpa_status;
    FPA_SRCMAC_LEARNING_MODE_ENT    learn_mode;
    
        
    MRVL_SAI_LOG_ENTER();

    if (SAI_STATUS_SUCCESS != (status = mrvl_sai_utl_object_to_type(key->object_id, SAI_OBJECT_TYPE_PORT, &port_id))) {
        return status;
    }

    switch (value->s32) {
    case SAI_PORT_LEARN_MODE_DISABLE:
        learn_mode = FPA_SRCMAC_LEARNING_FRWD_NONE_E;
        break;

    case SAI_PORT_LEARN_MODE_HW:
        learn_mode = FPA_SRCMAC_LEARNING_AUTO_E;
        break;

    case SAI_PORT_LEARN_MODE_DROP:
        learn_mode = FPA_SRCMAC_LEARNING_DROP_NONE_E;
        break;

    case SAI_PORT_LEARN_MODE_CPU_TRAP:
        learn_mode = FPA_SRCMAC_LEARNING_DROP_CTRL_E;
        break;

    case SAI_PORT_LEARN_MODE_CPU_LOG:
        learn_mode = FPA_SRCMAC_LEARNING_FRWD_CTRL_E;
        break;

    default:
        MRVL_SAI_LOG_ERR("Invalid port %d fdb learning mode %d\n", 
                         port_id, value->s32);
        return SAI_STATUS_INVALID_ATTR_VALUE_0;
    }

    fpa_status = fpaLibPortSrcMacLearningSet(SAI_DEFAULT_ETH_SWID_CNS, 
                                             port_id, 
                                             learn_mode);

    if (FPA_OK != fpa_status) {
        MRVL_SAI_LOG_ERR("Failed to set port %d MAC learning mode\n", port_id);
        return SAI_STATUS_FAILURE;
    }

    MRVL_SAI_LOG_EXIT();
    return SAI_STATUS_SUCCESS;
}
#endif
/* Default VLAN [sai_vlan_id_t]
 *   Untagged ingress frames are tagged with default VLAN
 */
sai_status_t mrvl_port_default_vlan_get(_In_ const sai_object_key_t   *key,
                                        _Inout_ sai_attribute_value_t *value,
                                        _In_ uint32_t                  attr_index,
                                        _Inout_ vendor_cache_t        *cache,
                                        void                          *arg)
{
    sai_status_t status;
    uint32_t     port_id;
    FPA_FLOW_TABLE_ENTRY_STC    fpa_flow_entry;
    FPA_STATUS                  fpa_status;
    uint64_t                    cookie;

    MRVL_SAI_LOG_ENTER();

    if (SAI_STATUS_SUCCESS != (status = mrvl_sai_utl_object_to_type(key->key.object_id, SAI_OBJECT_TYPE_PORT, &port_id))) {
        return status;
    }

    cookie = MRVL_SAI_VLAN_CREATE_COOKIE_MAC(0, port_id);
    fpa_flow_entry.cookie = cookie;
    fpa_status = fpaLibFlowTableGetByCookie(SAI_DEFAULT_ETH_SWID_CNS, 
                                            FPA_FLOW_TABLE_TYPE_VLAN_E, 
                                            &fpa_flow_entry);
    if (FPA_NOT_FOUND == fpa_status) {
        MRVL_SAI_LOG_ERR("No default VLAN entry %llx in fpa flow table status = %d\n",
                          cookie, fpa_status);
    } else if (FPA_OK != fpa_status) {
        MRVL_SAI_LOG_ERR("Failed to get VLAN entry %llx in fpa flow table status = %d\n",
                          cookie, fpa_status);
    } else if (FPA_FLOW_VLAN_IGNORE_VAL == fpa_flow_entry.data.vlan.newTagVid) {
        MRVL_SAI_LOG_ERR("Default VLAN for port %d was not configured\n", port_id);
        return SAI_STATUS_ITEM_NOT_FOUND;
    } else {
        value->u16 = fpa_flow_entry.data.vlan.newTagVid;
    }

    MRVL_SAI_LOG_EXIT();
    return mrvl_sai_utl_fpa_to_sai_status(fpa_status);
}

/* Default VLAN Priority [uint8_t]
 *  (default to 0) */
sai_status_t mrvl_port_default_vlan_prio_get(_In_ const sai_object_key_t   *key,
                                             _Inout_ sai_attribute_value_t *value,
                                             _In_ uint32_t                  attr_index,
                                             _Inout_ vendor_cache_t        *cache,
                                             void                          *arg)
{
    sai_status_t status;
    uint32_t     port_id;
    FPA_FLOW_TABLE_ENTRY_STC    fpa_flow_entry;
    FPA_STATUS                  fpa_status;
    uint64_t                    cookie;

    MRVL_SAI_LOG_ENTER();

    if (SAI_STATUS_SUCCESS != (status = mrvl_sai_utl_object_to_type(key->key.object_id, SAI_OBJECT_TYPE_PORT, &port_id))) {
        return status;
    }

    cookie = MRVL_SAI_VLAN_CREATE_COOKIE_MAC(0, port_id);
    fpa_flow_entry.cookie = cookie;
    fpa_status = fpaLibFlowTableGetByCookie(SAI_DEFAULT_ETH_SWID_CNS, 
                                            FPA_FLOW_TABLE_TYPE_VLAN_E, 
                                            &fpa_flow_entry);
    if (FPA_NOT_FOUND == fpa_status) {
        MRVL_SAI_LOG_ERR("No default VLAN priority entry %llx in fpa flow table status = %d\n",
                          cookie, fpa_status);
    } else if (FPA_OK != fpa_status) {
        MRVL_SAI_LOG_ERR("Failed to get VLAN entry %llx in fpa flow table status = %d\n",
                          cookie, fpa_status);
    } else if (FPA_FLOW_VLAN_IGNORE_VAL == fpa_flow_entry.data.vlan.newTagPcp) {
        MRVL_SAI_LOG_ERR("Default VLAN priority for port %d was not configured\n", port_id);
        return SAI_STATUS_ITEM_NOT_FOUND;
    } else {
        value->u8 = fpa_flow_entry.data.vlan.newTagPcp;
    }

    MRVL_SAI_LOG_EXIT();
    return mrvl_sai_utl_fpa_to_sai_status(fpa_status);
}

/* Default VLAN [sai_vlan_id_t]
 *   Untagged ingress frames are tagged with default VLAN
 */

sai_status_t mrvl_port_default_vlan_set(_In_ const sai_object_key_t      *key,
                                        _In_ const sai_attribute_value_t *value,
                                        void                             *arg)
{
    sai_status_t status;
    uint32_t     port_id;
    FPA_FLOW_TABLE_ENTRY_STC    fpa_flow_entry;
    FPA_STATUS                  fpa_status;
    uint64_t                    cookie;

    MRVL_SAI_LOG_ENTER();

    if (SAI_STATUS_SUCCESS != (status = mrvl_sai_utl_object_to_type(key->key.object_id, SAI_OBJECT_TYPE_PORT, &port_id))) {
        return status;
    }

    cookie = MRVL_SAI_VLAN_CREATE_COOKIE_MAC(0, port_id);
    fpa_flow_entry.cookie = cookie;
    fpa_status = fpaLibFlowTableGetByCookie(SAI_DEFAULT_ETH_SWID_CNS, 
                                            FPA_FLOW_TABLE_TYPE_VLAN_E, 
                                            &fpa_flow_entry);

    if (FPA_NOT_FOUND == fpa_status) {
        MRVL_SAI_LOG_NTC("No default VLAN entry %llx in fpa flow table status = %d\n",
                          cookie, fpa_status);
        fpa_status = fpaLibFlowEntryInit(SAI_DEFAULT_ETH_SWID_CNS, FPA_FLOW_TABLE_TYPE_VLAN_E, &fpa_flow_entry);
        if (fpa_status != FPA_OK) {
            MRVL_SAI_LOG_ERR("Failed to init VLAN entry status = %d\n", fpa_status);
            return mrvl_sai_utl_fpa_to_sai_status(fpa_status);
        }
         
        /* set default vlan entry */
        fpa_flow_entry.cookie = cookie; 
        fpa_flow_entry.data.vlan.vlanIdMask = FPA_FLOW_VLAN_MASK_UNTAG;
        fpa_flow_entry.data.vlan.inPort = port_id;
        fpa_flow_entry.data.vlan.newTagVid = value->u16;
        fpa_flow_entry.data.vlan.newTagPcp = FPA_FLOW_VLAN_IGNORE_VAL;

        fpa_status = fpaLibFlowEntryAdd(SAI_DEFAULT_ETH_SWID_CNS,
                                        FPA_FLOW_TABLE_TYPE_VLAN_E, 
                                        &fpa_flow_entry);
        if (status != FPA_OK) {
            MRVL_SAI_LOG_ERR("Failed to add VLAN entry %llx to fpa flow table status = %d\n",
                             cookie, fpa_status);
            
        }
    } else if (FPA_OK != fpa_status) {
        MRVL_SAI_LOG_ERR("Failed to get VLAN entry %llx to fpa flow table status = %d\n",
                          cookie, fpa_status);
    } else {
        MRVL_SAI_LOG_NTC("Modify default VLAN entry for port %d\n", port_id);
        fpa_flow_entry.data.vlan.vlanIdMask = FPA_FLOW_VLAN_MASK_UNTAG;
        fpa_flow_entry.data.vlan.newTagVid = value->u16; 
        fpa_flow_entry.data.vlan.newTagPcp = FPA_FLOW_VLAN_IGNORE_VAL;
        fpa_status = fpaLibFlowEntryModify(SAI_DEFAULT_ETH_SWID_CNS, 
                                           FPA_FLOW_TABLE_TYPE_VLAN_E, 
                                           &fpa_flow_entry, 0);
        if (fpa_status != FPA_OK) {
            MRVL_SAI_LOG_ERR("Failed to modify VLAN entry %llx to fpa flow table status = %d\n",
                             cookie, fpa_status);
        }
    }

    MRVL_SAI_LOG_EXIT();
    return mrvl_sai_utl_fpa_to_sai_status(fpa_status);
}

/* Default VLAN Priority [uint8_t]
 *  (default to 0) */
sai_status_t mrvl_port_default_vlan_prio_set(_In_ const sai_object_key_t      *key,
                                             _In_ const sai_attribute_value_t *value,
                                             void                             *arg)
{
    sai_status_t status;
    uint32_t     port_id;
    FPA_FLOW_TABLE_ENTRY_STC    fpa_flow_entry;
    FPA_STATUS                  fpa_status;
    uint64_t                    cookie;

    MRVL_SAI_LOG_ENTER();

    if (SAI_STATUS_SUCCESS != (status = mrvl_sai_utl_object_to_type(key->key.object_id, SAI_OBJECT_TYPE_PORT, &port_id))) {
        return status;
    }

    cookie = MRVL_SAI_VLAN_CREATE_COOKIE_MAC(0, port_id);
    fpa_flow_entry.cookie = cookie;
    fpa_status = fpaLibFlowTableGetByCookie(SAI_DEFAULT_ETH_SWID_CNS, 
                                            FPA_FLOW_TABLE_TYPE_VLAN_E, 
                                            &fpa_flow_entry);

    if (FPA_NOT_FOUND == fpa_status) {
        MRVL_SAI_LOG_ERR("No default VLAN entry %llx in fpa flow table status = %d\n",
                          cookie, fpa_status);
    } else if (FPA_OK != fpa_status) {
        MRVL_SAI_LOG_ERR("Failed to get VLAN entry %llx to fpa flow table status = %d\n",
                          cookie, fpa_status);
    } else {
        MRVL_SAI_LOG_NTC("Modify default VLAN priority entry for port %d\n", port_id);
        fpa_flow_entry.data.vlan.newTagPcp = value->u8;
        fpa_status = fpaLibFlowEntryModify(SAI_DEFAULT_ETH_SWID_CNS, 
                                           FPA_FLOW_TABLE_TYPE_VLAN_E, 
                                           &fpa_flow_entry, 0);
        if (fpa_status != FPA_OK) {
            MRVL_SAI_LOG_ERR("Failed to modify VLAN entry %llx to fpa flow table status = %d\n",
                             cookie, fpa_status);
        }
    }

    MRVL_SAI_LOG_EXIT();
    return mrvl_sai_utl_fpa_to_sai_status(fpa_status);
}

sai_status_t mrvl_port_acl_binding_set(_In_ const sai_object_key_t      *key,
                                       _In_ const sai_attribute_value_t *value,
                                       _In_ void                        *arg)
{
    sai_status_t status = SAI_STATUS_SUCCESS;
    uint32_t     port;

    MRVL_SAI_LOG_ENTER();

    if (SAI_STATUS_SUCCESS != (status = mrvl_sai_utl_object_to_type(key->key.object_id, SAI_OBJECT_TYPE_PORT, &port))) {
        return status;
    }

    if (port > SAI_MAX_NUM_OF_PORTS){
        MRVL_SAI_LOG_ERR("Invalid port %d\n", port);
        return SAI_STATUS_INVALID_PARAMETER;
    }

    if (value->oid == SAI_NULL_OBJECT_ID){
    	/* unbind action */
    	if (SAI_STATUS_SUCCESS != (status = mrvl_sai_acl_table_unbind_from_port(arg, port))){
            MRVL_SAI_LOG_ERR("Unable to unbind port %d from ACL TABLE\n", port);
            return SAI_STATUS_INVALID_PARAMETER;
    	}
    }
    else {
    	if (SAI_STATUS_SUCCESS != (status = mrvl_sai_acl_table_bind_to_port(arg, value->oid, port))){
            MRVL_SAI_LOG_ERR("Unable to bind port %d to ACL TABLE\n", port);
            return SAI_STATUS_INVALID_PARAMETER;
    	}
    }

    MRVL_SAI_LOG_EXIT();
    return status;
}

sai_status_t mrvl_port_acl_binding_get(_In_ const sai_object_key_t   *key,
                                       _Inout_ sai_attribute_value_t *value,
                                       _In_ uint32_t                  attr_index,
                                       _Inout_ vendor_cache_t        *cache,
                                       void                          *arg){
    sai_status_t status = SAI_STATUS_SUCCESS;
    uint32_t     port;


    MRVL_SAI_LOG_ENTER();

    if (SAI_STATUS_SUCCESS != (status = mrvl_sai_utl_object_to_type(key->key.object_id, SAI_OBJECT_TYPE_PORT, &port))) {
        return status;
    }

    if (port > SAI_MAX_NUM_OF_PORTS){
        MRVL_SAI_LOG_ERR("Invalid port %d\n", port);
        return SAI_STATUS_INVALID_PARAMETER;
    }

    if (SAI_STATUS_SUCCESS != (status = mrvl_sai_acl_get_table_id_per_port(arg, port, value))){
        MRVL_SAI_LOG_ERR("Unable to get assigned ACL table per port %d\n", port);
        return SAI_STATUS_INVALID_PARAMETER;
    }

    MRVL_SAI_LOG_EXIT();
    return status;

}
#if 0
sai_status_t mrvl_sai_add_port_prv(sai_port_info_t *port)
{
    sai_status_t status;

    if (SAI_STATUS_SUCCESS != (status = mrvl_sai_port_config_init_prv(port))){
        MRVL_SAI_LOG_ERR("Failed to init configuration for port %d\n", port->logical_port);
        MRVL_SAI_API_RETURN(status);
    }
    
    /*if (SAI_STATUS_SUCCESS != (status = mrvl_sai_acl_port_lag_event_handle_prv(port_idx, ACL_EVENT_TYPE_PORT_LAG_ADD))){
        MRVL_SAI_LOG_ERR("Failed to handle acl port lag event for port %d\n", port->logical_port);
        MRVL_SAI_API_RETURN(status);*/
    
    return SAI_STATUS_SUCCESS;
}
#endif
/**
 * @brief Create port
 *
 * @param[out] port_id Port id
 * @param[in] switch_id Switch id
 * @param[in] attr_count Number of attributes
 * @param[in] attr_list Array of attributes
 *
 * @return #SAI_STATUS_SUCCESS on success Failure status code on error
 */
sai_status_t mrvl_create_port(
        _Out_ sai_object_id_t *port_id,
        _In_ sai_object_id_t switch_id,
        _In_ uint32_t attr_count,
        _In_ const sai_attribute_t *attr_list)
{
    sai_status_t                 status;  
    uint32_t                     lane_count, index;
    static uint32_t              port_idx = 0; /* TO DO: dynamic port idx allocation */
    sai_port_info_t              *port = NULL;
    char                         list_str[MAX_LIST_VALUE_STR_LEN];
    char                         key_str[MAX_KEY_STR_LEN];
    const sai_attribute_value_t *hw_lane_list = NULL;
    const sai_attribute_value_t *speed = NULL;   
    const sai_attribute_value_t *ingress_acl = NULL, *egress_acl = NULL;   

    MRVL_SAI_LOG_ENTER();

    if (NULL == port_id) {
        MRVL_SAI_LOG_ERR("NULL port id param\n");
        MRVL_SAI_API_RETURN(SAI_STATUS_INVALID_PARAMETER);
    }

    if (port_idx == SAI_MAX_NUM_OF_PORTS)
    {
        MRVL_SAI_LOG_ERR("Reached max number of ports possible: %d\n", SAI_MAX_NUM_OF_PORTS);
        MRVL_SAI_API_RETURN(SAI_STATUS_TABLE_FULL);
    }
    status = mrvl_sai_utl_check_attribs_metadata(attr_count, attr_list, port_attribs, port_vendor_attribs, 
                                                 SAI_COMMON_API_CREATE);
    if (SAI_STATUS_SUCCESS != status) {
        MRVL_SAI_LOG_ERR("Failed port attributes check\n");
        MRVL_SAI_API_RETURN(status);
    }

    mrvl_sai_utl_attr_list_to_str(attr_count, attr_list, port_attribs, MAX_LIST_VALUE_STR_LEN, list_str);    
    MRVL_SAI_LOG_NTC("Create port, %s\n", list_str);

    /* find port mandatory attributes: */
    /*assert(SAI_STATUS_SUCCESS !=
           mrvl_sai_utl_find_attrib_in_list(attr_count, attr_list, SAI_PORT_ATTR_HW_LANE_LIST, &hw_lane_list, &index));*/
    /*assert(SAI_STATUS_SUCCESS !=*/
    status = mrvl_sai_utl_find_attrib_in_list(attr_count, attr_list, SAI_PORT_ATTR_SPEED, &speed, &index);
    if (SAI_STATUS_SUCCESS != status)
    {
        MRVL_SAI_LOG_ERR("Find SAI_PORT_ATTR_SPEED: Invalid status returned: %d\n", status);
    }

    /*lane_count = hw_lane_list->u32list.count;
    if (0 == lane_count || 3 == lane_count) {
        MRVL_SAI_LOG_ERR("Port HW lanes count %u is invalid (supported only 1,2,4)\n", lane_count);
        MRVL_SAI_API_RETURN(SAI_STATUS_INVALID_PARAMETER);
    }
    if (lane_count > SAI_MAX_NUM_OF_LANES) {
        MRVL_SAI_LOG_ERR("Port HW lanes count %u is bigger than %u\n", lane_count, SAI_MAX_NUM_OF_LANES);
        MRVL_SAI_API_RETURN(SAI_STATUS_INVALID_PARAMETER);
    }*/

    /* check SAI_PORT_ATTR_INGRESS_ACL & SAI_PORT_ATTR_EGRESS_ACL */
    /*assert(SAI_STATUS_SUCCESS !=*/
    status = mrvl_sai_utl_find_attrib_in_list(attr_count, attr_list, SAI_PORT_ATTR_INGRESS_ACL, &ingress_acl, &index);
    if (SAI_STATUS_SUCCESS != status)
    {
        MRVL_SAI_LOG_ERR("Find SAI_PORT_ATTR_INGRESS_ACL: Invalid status returned: %d\n", status);
    }
    /*assert(SAI_STATUS_SUCCESS !=*/
    status = mrvl_sai_utl_find_attrib_in_list(attr_count, attr_list, SAI_PORT_ATTR_EGRESS_ACL, &egress_acl, &index);
    if (SAI_STATUS_SUCCESS != status)
    {
        MRVL_SAI_LOG_ERR("Find SAI_PORT_ATTR_EGRESS_ACL: Invalid status returned: %d\n", status);
    }

    /* create SAI port object */    
    if (SAI_STATUS_SUCCESS != (status = mrvl_sai_utl_create_object(SAI_OBJECT_TYPE_PORT, SAI_SYS_PORT_MAPPING[port_idx], port_id))) {
        MRVL_SAI_API_RETURN(status);
    }

    
    status = mrvl_sai_utl_create_l2_int_group_wo_vlan(SAI_SYS_PORT_MAPPING[port_idx]);
    if (status != SAI_STATUS_SUCCESS) {
        MRVL_SAI_LOG_ERR("Can't create l2 interface group w/o vlan for port %d\n", SAI_SYS_PORT_MAPPING[port_idx]);
        MRVL_SAI_API_RETURN(SAI_STATUS_FAILURE);
    }

    port_key_to_str(*port_id, key_str);
    MRVL_SAI_LOG_NTC("Created %s\n", key_str);

    port_idx++;
    MRVL_SAI_LOG_EXIT();
    MRVL_SAI_API_RETURN(SAI_STATUS_SUCCESS);    

}
/**
 * @brief Remove port
 *
 * @param[in] port_id Port id
 *
 * @return #SAI_STATUS_SUCCESS on success Failure status code on error
 */
sai_status_t mrvl_remove_port(
        _In_ sai_object_id_t port_id)
{
    uint32_t            port_idx;       

    MRVL_SAI_LOG_ENTER();        

    if (SAI_STATUS_SUCCESS != mrvl_sai_utl_object_to_type(port_id, SAI_OBJECT_TYPE_PORT, &port_idx)) {
        MRVL_SAI_LOG_ERR("invalid port_idx %d\n",port_idx);
        MRVL_SAI_API_RETURN(SAI_STATUS_INVALID_PARAMETER);
    }

    MRVL_SAI_LOG_EXIT();
    MRVL_SAI_API_RETURN(SAI_STATUS_SUCCESS);

}


#if 0
sai_status_t mrvl_port_fdb_violation_set(_In_ const sai_object_key_t      *key,
                                         _In_ const sai_attribute_value_t *value,
                                         void                             *arg);
sai_status_t mrvl_port_max_learned_addr_set(_In_ const sai_object_key_t      *key,
                                            _In_ const sai_attribute_value_t *value,
                                            void                             *arg);
sai_status_t mrvl_port_storm_control_set(_In_ const sai_object_key_t      *key,
                                         _In_ const sai_attribute_value_t *value,
                                         void                             *arg);
sai_status_t mrvl_port_update_dscp_set(_In_ const sai_object_key_t      *key,
                                       _In_ const sai_attribute_value_t *value,
                                       void                             *arg);
sai_status_t mrvl_port_media_type_set(_In_ const sai_object_key_t      *key,
                                      _In_ const sai_attribute_value_t *value,
                                      void                             *arg);
sai_status_t mrvl_port_ingress_filter_set(_In_ const sai_object_key_t      *key,
                                          _In_ const sai_attribute_value_t *value,
                                          void                             *arg);
sai_status_t mrvl_port_drop_tags_set(_In_ const sai_object_key_t      *key,
                                     _In_ const sai_attribute_value_t *value,
                                     void                             *arg);
sai_status_t mrvl_port_internal_loopback_set(_In_ const sai_object_key_t      *key,
                                             _In_ const sai_attribute_value_t *value,
                                             void                             *arg);
sai_status_t mrvl_port_mtu_set(_In_ const sai_object_key_t      *key,
                               _In_ const sai_attribute_value_t *value,
                               void                             *arg);
sai_status_t mrvl_port_type_get(_In_ const sai_object_key_t   *key,
                                _Inout_ sai_attribute_value_t *value,
                                _In_ uint32_t                  attr_index,
                                _Inout_ vendor_cache_t        *cache,
                                void                          *arg);
sai_status_t mrvl_port_max_learned_addr_get(_In_ const sai_object_key_t   *key,
                                            _Inout_ sai_attribute_value_t *value,
                                            _In_ uint32_t                  attr_index,
                                            _Inout_ vendor_cache_t        *cache,
                                            void                          *arg);
sai_status_t mrvl_port_fdb_violation_get(_In_ const sai_object_key_t   *key,
                                         _Inout_ sai_attribute_value_t *value,
                                         _In_ uint32_t                  attr_index,
                                         _Inout_ vendor_cache_t        *cache,
                                         void                          *arg);
sai_status_t mrvl_port_media_type_get(_In_ const sai_object_key_t   *key,
                                      _Inout_ sai_attribute_value_t *value,
                                      _In_ uint32_t                  attr_index,
                                      _Inout_ vendor_cache_t        *cache,
                                      void                          *arg);
sai_status_t mrvl_port_storm_control_get(_In_ const sai_object_key_t   *key,
                                         _Inout_ sai_attribute_value_t *value,
                                         _In_ uint32_t                  attr_index,
                                         _Inout_ vendor_cache_t        *cache,
                                         void                          *arg);
sai_status_t mrvl_port_update_dscp_get(_In_ const sai_object_key_t   *key,
                                       _Inout_ sai_attribute_value_t *value,
                                       _In_ uint32_t                  attr_index,
                                       _Inout_ vendor_cache_t        *cache,
                                       void                          *arg);
sai_status_t mrvl_port_hw_lanes_get(_In_ const sai_object_key_t   *key,
                                    _Inout_ sai_attribute_value_t *value,
                                    _In_ uint32_t                  attr_index,
                                    _Inout_ vendor_cache_t        *cache,
                                    void                          *arg);
sai_status_t mrvl_port_supported_breakout_get(_In_ const sai_object_key_t   *key,
                                              _Inout_ sai_attribute_value_t *value,
                                              _In_ uint32_t                  attr_index,
                                              _Inout_ vendor_cache_t        *cache,
                                              void                          *arg);
sai_status_t mrvl_port_current_breakout_get(_In_ const sai_object_key_t   *key,
                                            _Inout_ sai_attribute_value_t *value,
                                            _In_ uint32_t                  attr_index,
                                            _Inout_ vendor_cache_t        *cache,
                                            void                          *arg);
sai_status_t mrvl_port_ingress_filter_get(_In_ const sai_object_key_t   *key,
                                          _Inout_ sai_attribute_value_t *value,
                                          _In_ uint32_t                  attr_index,
                                          _Inout_ vendor_cache_t        *cache,
                                          void                          *arg);
sai_status_t mrvl_port_drop_tags_get(_In_ const sai_object_key_t   *key,
                                     _Inout_ sai_attribute_value_t *value,
                                     _In_ uint32_t                  attr_index,
                                     _Inout_ vendor_cache_t        *cache,
                                     void                          *arg);
sai_status_t mrvl_port_internal_loopback_get(_In_ const sai_object_key_t   *key,
                                             _Inout_ sai_attribute_value_t *value,
                                             _In_ uint32_t                  attr_index,
                                             _Inout_ vendor_cache_t        *cache,
                                             void                          *arg);
sai_status_t mrvl_port_mtu_get(_In_ const sai_object_key_t   *key,
                               _Inout_ sai_attribute_value_t *value,
                               _In_ uint32_t                  attr_index,
                               _Inout_ vendor_cache_t        *cache,
                               void                          *arg);
#endif

#if 0
static const sai_attribute_entry_t        port_attribs[] = {
    { SAI_PORT_ATTR_TYPE, false, false, false, true,
      "Port type", SAI_ATTR_VAL_TYPE_S32 },
    { SAI_PORT_ATTR_HW_LANE_LIST, false, false, false, true,
      "Port HW lane list", SAI_ATTR_VAL_TYPE_U32LIST },
    { SAI_PORT_ATTR_SUPPORTED_BREAKOUT_MODE, false, false, false, true,
      "Port supported breakout modes", SAI_ATTR_VAL_TYPE_S32LIST },
    { SAI_PORT_ATTR_CURRENT_BREAKOUT_MODE, false, false, false, true,
      "Port current breakout mode", SAI_ATTR_VAL_TYPE_S32 },
    { SAI_PORT_ATTR_MEDIA_TYPE, false, false, true, true,
      "Port media type", SAI_ATTR_VAL_TYPE_S32 },
    { SAI_PORT_ATTR_INGRESS_FILTERING, false, false, true, true,
      "Port ingress filtering", SAI_ATTR_VAL_TYPE_BOOL },
    { SAI_PORT_ATTR_DROP_UNTAGGED, false, false, true, true,
      "Port drop untageed", SAI_ATTR_VAL_TYPE_BOOL },
    { SAI_PORT_ATTR_DROP_TAGGED, false, false, true, true,
      "Port drop tageed", SAI_ATTR_VAL_TYPE_BOOL },
    { SAI_PORT_ATTR_INTERNAL_LOOPBACK, false, false, true, true,
      "Port internal loopback", SAI_ATTR_VAL_TYPE_S32 },
    { SAI_PORT_ATTR_UPDATE_DSCP, false, false, true, true,
      "Port update DSCP", SAI_ATTR_VAL_TYPE_BOOL },
    { SAI_PORT_ATTR_MTU, false, false, true, true,
      "Port mtu", SAI_ATTR_VAL_TYPE_U32 },
    { SAI_PORT_ATTR_FLOOD_STORM_CONTROL, false, false, true, true,
      "Port flood storm control", SAI_ATTR_VAL_TYPE_BOOL },
    { SAI_PORT_ATTR_BROADCAST_STORM_CONTROL, false, false, true, true,
      "Port broadcast storm control", SAI_ATTR_VAL_TYPE_BOOL },
    { SAI_PORT_ATTR_MULTICAST_STORM_CONTROL, false, false, true, true,
      "Port multicast storm control", SAI_ATTR_VAL_TYPE_BOOL },
    { SAI_PORT_ATTR_GLOBAL_FLOW_CONTROL, false, false, true, true,
      "Port global flow control", SAI_ATTR_VAL_TYPE_S32 },
    { SAI_PORT_ATTR_MAX_LEARNED_ADDRESSES, false, false, true, true,
      "Port max learned addresses", SAI_ATTR_VAL_TYPE_U32 },
    { SAI_PORT_ATTR_FDB_LEARNING_LIMIT_VIOLATION, false, false, true, true,
      "Port fdb learning limit violation", SAI_ATTR_VAL_TYPE_S32 },
    { SAI_PORT_ATTR_INGRESS_MIRROR_SESSION, false, false, true, true,
      "Port ingress mirror session", SAI_ATTR_VAL_TYPE_OBJLIST },
    { SAI_PORT_ATTR_EGRESS_MIRROR_SESSION, false, false, true, true,
      "Port egress mirror session", SAI_ATTR_VAL_TYPE_OBJLIST },
    { SAI_PORT_ATTR_INGRESS_SAMPLEPACKET_ENABLE, false, false, true, true,
      "Port ingress samplepacket enable", SAI_ATTR_VAL_TYPE_OID },
    { SAI_PORT_ATTR_EGRESS_SAMPLEPACKET_ENABLE, false, false, true, true,
      "Port egress samplepacket enable", SAI_ATTR_VAL_TYPE_OID },
    { END_FUNCTIONALITY_ATTRIBS_ID, false, false, false, false,
      "", SAI_ATTR_VAL_TYPE_UNDETERMINED }
};
static const sai_vendor_attribute_entry_t port_vendor_attribs[] = {
    { SAI_PORT_ATTR_TYPE,
      { false, false, false, true },
      { false, false, false, true },
      mrvl_port_type_get, NULL,
      NULL, NULL },
    { SAI_PORT_ATTR_HW_LANE_LIST,
      { false, false, false, true },
      { false, false, false, true },
      mrvl_port_hw_lanes_get, NULL,
      NULL, NULL },
    { SAI_PORT_ATTR_SUPPORTED_BREAKOUT_MODE,
      { false, false, false, true },
      { false, false, false, true },
      mrvl_port_supported_breakout_get, NULL,
      NULL, NULL },
    { SAI_PORT_ATTR_CURRENT_BREAKOUT_MODE,
      { false, false, false, true },
      { false, false, false, true },
      mrvl_port_current_breakout_get, NULL,
      NULL, NULL },
    { SAI_PORT_ATTR_MEDIA_TYPE,
      { false, false, true, true },
      { false, false, true, true },
      mrvl_port_media_type_get, NULL,
      mrvl_port_media_type_set, NULL },
    { SAI_PORT_ATTR_INGRESS_FILTERING,
      { false, false, true, true },
      { false, false, true, true },
      mrvl_port_ingress_filter_get, NULL,
      mrvl_port_ingress_filter_set, NULL },
    { SAI_PORT_ATTR_DROP_UNTAGGED,
      { false, false, true, true },
      { false, false, true, true },
      mrvl_port_drop_tags_get, (void*)SAI_PORT_ATTR_DROP_UNTAGGED,
      mrvl_port_drop_tags_set, (void*)SAI_PORT_ATTR_DROP_UNTAGGED },
    { SAI_PORT_ATTR_DROP_TAGGED,
      { false, false, true, true },
      { false, false, true, true },
      mrvl_port_drop_tags_get, (void*)SAI_PORT_ATTR_DROP_TAGGED,
      mrvl_port_drop_tags_set, (void*)SAI_PORT_ATTR_DROP_TAGGED },
    { SAI_PORT_ATTR_INTERNAL_LOOPBACK,
      { false, false, true, true },
      { false, false, true, true },
      mrvl_port_internal_loopback_get, NULL,
      mrvl_port_internal_loopback_set, NULL },
    { SAI_PORT_ATTR_UPDATE_DSCP,
      { false, false, true, true },
      { false, false, true, true },
      mrvl_port_update_dscp_get, NULL,
      mrvl_port_update_dscp_set, NULL },
    { SAI_PORT_ATTR_MTU,
      { false, false, true, true },
      { false, false, true, true },
      mrvl_port_mtu_get, NULL,
      mrvl_port_mtu_set, NULL },
    { SAI_PORT_ATTR_FLOOD_STORM_CONTROL,
      { false, false, true, true },
      { false, false, true, true },
      mrvl_port_storm_control_get, (void*)SAI_PORT_ATTR_FLOOD_STORM_CONTROL,
      mrvl_port_storm_control_set, (void*)SAI_PORT_ATTR_FLOOD_STORM_CONTROL },
    { SAI_PORT_ATTR_BROADCAST_STORM_CONTROL,
      { false, false, true, true },
      { false, false, true, true },
      mrvl_port_storm_control_get, (void*)SAI_PORT_ATTR_BROADCAST_STORM_CONTROL,
      mrvl_port_storm_control_set, (void*)SAI_PORT_ATTR_BROADCAST_STORM_CONTROL },
    { SAI_PORT_ATTR_MULTICAST_STORM_CONTROL,
      { false, false, true, true },
      { false, false, true, true },
      mrvl_port_storm_control_get, (void*)SAI_PORT_ATTR_MULTICAST_STORM_CONTROL,
      mrvl_port_storm_control_set, (void*)SAI_PORT_ATTR_MULTICAST_STORM_CONTROL },
    { SAI_PORT_ATTR_GLOBAL_FLOW_CONTROL,
      { false, false, false, false },
      { false, false, true, true },
      NULL, NULL,
      NULL, NULL },
    { SAI_PORT_ATTR_MAX_LEARNED_ADDRESSES,
      { false, false, true, true },
      { false, false, true, true },
      mrvl_port_max_learned_addr_get, NULL,
      mrvl_port_max_learned_addr_set, NULL },
    { SAI_PORT_ATTR_FDB_LEARNING_LIMIT_VIOLATION,
      { false, false, false, false },
      { false, false, true, true },
      mrvl_port_fdb_violation_get, NULL,
      mrvl_port_fdb_violation_set, NULL },
    { SAI_PORT_ATTR_INGRESS_MIRROR_SESSION,
      { false, false, false, false },
      { false, false, true, true },
      NULL, NULL,
      NULL, NULL },
    { SAI_PORT_ATTR_EGRESS_MIRROR_SESSION,
      { false, false, false, false },
      { false, false, true, true },
      NULL, NULL,
      NULL, NULL },
    { SAI_PORT_ATTR_INGRESS_SAMPLEPACKET_ENABLE,
      { false, false, false, false },
      { false, false, true, true },
      NULL, NULL,
      NULL, NULL },
    { SAI_PORT_ATTR_EGRESS_SAMPLEPACKET_ENABLE,
      { false, false, false, false },
      { false, false, true, true },
      NULL, NULL,
      NULL, NULL }
};

/* Update DSCP of outgoing packets [bool] */
sai_status_t mrvl_port_update_dscp_set(_In_ const sai_object_key_t      *key,
                                       _In_ const sai_attribute_value_t *value,
                                       void                             *arg)
{
    sai_status_t status;
    uint32_t     port_id;

    MRVL_SAI_LOG_ENTER();

    if (SAI_STATUS_SUCCESS != (status = mrvl_object_to_type(key->object_id, SAI_OBJECT_TYPE_PORT, &port_id))) {
        return status;
    }

    MRVL_SAI_LOG_EXIT();
    return SAI_STATUS_SUCCESS;
}

/* [bool] (default to FALSE) */
sai_status_t mrvl_port_storm_control_set(_In_ const sai_object_key_t      *key,
                                         _In_ const sai_attribute_value_t *value,
                                         void                             *arg)
{
    sai_status_t status;
    uint32_t     port_id;

    MRVL_SAI_LOG_ENTER();

    if (SAI_STATUS_SUCCESS != (status = mrvl_object_to_type(key->object_id, SAI_OBJECT_TYPE_PORT, &port_id))) {
        return status;
    }

    MRVL_SAI_LOG_EXIT();
    return SAI_STATUS_SUCCESS;
}

/* Action for packets with unknown source mac address
 * when FDB learning limit is reached.
 * [sai_packet_action_t] (default to SAI_PACKET_ACTION_DROP) */
sai_status_t mrvl_port_fdb_violation_set(_In_ const sai_object_key_t      *key,
                                         _In_ const sai_attribute_value_t *value,
                                         void                             *arg)
{
    sai_status_t status;
    uint32_t     port_id;

    MRVL_SAI_LOG_ENTER();

    if (SAI_STATUS_SUCCESS != (status = mrvl_object_to_type(key->object_id, SAI_OBJECT_TYPE_PORT, &port_id))) {
        return status;
    }

    MRVL_SAI_LOG_EXIT();
    return SAI_STATUS_SUCCESS;
}

/* Maximum number of learned MAC addresses [uint32_t] */
sai_status_t mrvl_port_max_learned_addr_set(_In_ const sai_object_key_t      *key,
                                            _In_ const sai_attribute_value_t *value,
                                            void                             *arg)
{
    sai_status_t status;
    uint32_t     port_id;

    MRVL_SAI_LOG_ENTER();

    if (SAI_STATUS_SUCCESS != (status = mrvl_object_to_type(key->object_id, SAI_OBJECT_TYPE_PORT, &port_id))) {
        return status;
    }

    MRVL_SAI_LOG_EXIT();
    return SAI_STATUS_SUCCESS;
}

/* Media Type [sai_port_media_type_t] */
sai_status_t mrvl_port_media_type_set(_In_ const sai_object_key_t      *key,
                                      _In_ const sai_attribute_value_t *value,
                                      void                             *arg)
{
    sai_status_t status;
    uint32_t     port_id;

    MRVL_SAI_LOG_ENTER();

    if (SAI_STATUS_SUCCESS != (status = mrvl_object_to_type(key->object_id, SAI_OBJECT_TYPE_PORT, &port_id))) {
        return status;
    }

    MRVL_SAI_LOG_EXIT();
    return SAI_STATUS_SUCCESS;
}

/* Ingress Filtering (Drop Frames with Unknown VLANs) [bool] */
sai_status_t mrvl_port_ingress_filter_set(_In_ const sai_object_key_t      *key,
                                          _In_ const sai_attribute_value_t *value,
                                          void                             *arg)
{
    sai_status_t status;
    uint32_t     port_id;

    MRVL_SAI_LOG_ENTER();

    if (SAI_STATUS_SUCCESS != (status = mrvl_object_to_type(key->object_id, SAI_OBJECT_TYPE_PORT, &port_id))) {
        return status;
    }

    MRVL_SAI_LOG_EXIT();
    return SAI_STATUS_SUCCESS;
}

/* Dropping of untagged frames on ingress [bool] */
/* Dropping of tagged frames on ingress [bool] */
sai_status_t mrvl_port_drop_tags_set(_In_ const sai_object_key_t      *key,
                                     _In_ const sai_attribute_value_t *value,
                                     void                             *arg)
{
    sai_status_t status;
    uint32_t     port_id;

    MRVL_SAI_LOG_ENTER();

    assert((SAI_PORT_ATTR_DROP_UNTAGGED == (int64_t)arg) || (SAI_PORT_ATTR_DROP_TAGGED == (int64_t)arg));

    if (SAI_STATUS_SUCCESS != (status = mrvl_object_to_type(key->object_id, SAI_OBJECT_TYPE_PORT, &port_id))) {
        return status;
    }

    MRVL_SAI_LOG_EXIT();
    return SAI_STATUS_SUCCESS;
}

/* Internal loopback control [sai_port_loopback_mode_t] */
sai_status_t mrvl_port_internal_loopback_set(_In_ const sai_object_key_t      *key,
                                             _In_ const sai_attribute_value_t *value,
                                             void                             *arg)
{
    sai_status_t status;
    uint32_t     port_id;

    MRVL_SAI_LOG_ENTER();

    if (SAI_STATUS_SUCCESS != (status = mrvl_object_to_type(key->object_id, SAI_OBJECT_TYPE_PORT, &port_id))) {
        return status;
    }

    switch (value->s32) {
    case SAI_PORT_INTERNAL_LOOPBACK_NONE:
        break;

    case SAI_PORT_INTERNAL_LOOPBACK_PHY:
        break;

    case SAI_PORT_INTERNAL_LOOPBACK_MAC:
        break;

    default:
        MRVL_SAI_LOG_ERR("Invalid port internal loopback value %d\n", value->s32);
        return SAI_STATUS_INVALID_ATTR_VALUE_0;
    }

    MRVL_SAI_LOG_EXIT();
    return SAI_STATUS_SUCCESS;
}

/* MTU [uint32_t] */
sai_status_t mrvl_port_mtu_set(_In_ const sai_object_key_t *key, _In_ const sai_attribute_value_t *value, void *arg)
{
    sai_status_t status;
    uint32_t     port_id;

    MRVL_SAI_LOG_ENTER();

    if (SAI_STATUS_SUCCESS != (status = mrvl_object_to_type(key->object_id, SAI_OBJECT_TYPE_PORT, &port_id))) {
        return status;
    }

    MRVL_SAI_LOG_EXIT();
    return SAI_STATUS_SUCCESS;
}

/* Port type [sai_port_type_t] */
sai_status_t mrvl_port_type_get(_In_ const sai_object_key_t   *key,
                                _Inout_ sai_attribute_value_t *value,
                                _In_ uint32_t                  attr_index,
                                _Inout_ vendor_cache_t        *cache,
                                void                          *arg)
{
    sai_status_t status;
    uint32_t     port_id;

    MRVL_SAI_LOG_ENTER();

    if (SAI_STATUS_SUCCESS != (status = mrvl_object_to_type(key->object_id, SAI_OBJECT_TYPE_PORT, &port_id))) {
        return status;
    }

    value->s32 = SAI_PORT_TYPE_LOGICAL;

    MRVL_SAI_LOG_EXIT();
    return SAI_STATUS_SUCCESS;
}

/* Maximum number of learned MAC addresses [uint32_t] */
sai_status_t mrvl_port_max_learned_addr_get(_In_ const sai_object_key_t   *key,
                                            _Inout_ sai_attribute_value_t *value,
                                            _In_ uint32_t                  attr_index,
                                            _Inout_ vendor_cache_t        *cache,
                                            void                          *arg)
{
    sai_status_t status;
    uint32_t     port_id;

    MRVL_SAI_LOG_ENTER();

    if (SAI_STATUS_SUCCESS != (status = mrvl_object_to_type(key->object_id, SAI_OBJECT_TYPE_PORT, &port_id))) {
        return status;
    }

    value->u32 = 100000;

    MRVL_SAI_LOG_EXIT();
    return SAI_STATUS_SUCCESS;
}

/* Action for packets with unknown source mac address
 * when FDB learning limit is reached.
 * [sai_packet_action_t] (default to SAI_PACKET_ACTION_DROP) */
sai_status_t mrvl_port_fdb_violation_get(_In_ const sai_object_key_t   *key,
                                         _Inout_ sai_attribute_value_t *value,
                                         _In_ uint32_t                  attr_index,
                                         _Inout_ vendor_cache_t        *cache,
                                         void                          *arg)
{
    sai_status_t status;
    uint32_t     port_id;

    MRVL_SAI_LOG_ENTER();

    if (SAI_STATUS_SUCCESS != (status = mrvl_object_to_type(key->object_id, SAI_OBJECT_TYPE_PORT, &port_id))) {
        return status;
    }

    value->s32 = SAI_PACKET_ACTION_DROP;

    MRVL_SAI_LOG_EXIT();
    return SAI_STATUS_SUCCESS;
}

/* Media Type [sai_port_media_type_t] */
sai_status_t mrvl_port_media_type_get(_In_ const sai_object_key_t   *key,
                                      _Inout_ sai_attribute_value_t *value,
                                      _In_ uint32_t                  attr_index,
                                      _Inout_ vendor_cache_t        *cache,
                                      void                          *arg)
{
    sai_status_t status;
    uint32_t     port_id;

    MRVL_SAI_LOG_ENTER();

    if (SAI_STATUS_SUCCESS != (status = mrvl_object_to_type(key->object_id, SAI_OBJECT_TYPE_PORT, &port_id))) {
        return status;
    }

    value->s32 = SAI_PORT_MEDIA_TYPE_QSFP_COPPER;

    MRVL_SAI_LOG_EXIT();
    return SAI_STATUS_SUCCESS;
}

/* Update DSCP of outgoing packets [bool] */
sai_status_t mrvl_port_update_dscp_get(_In_ const sai_object_key_t   *key,
                                       _Inout_ sai_attribute_value_t *value,
                                       _In_ uint32_t                  attr_index,
                                       _Inout_ vendor_cache_t        *cache,
                                       void                          *arg)
{
    sai_status_t status;
    uint32_t     port_id;

    MRVL_SAI_LOG_ENTER();

    if (SAI_STATUS_SUCCESS != (status = mrvl_object_to_type(key->object_id, SAI_OBJECT_TYPE_PORT, &port_id))) {
        return status;
    }

    value->booldata = false;

    MRVL_SAI_LOG_EXIT();
    return SAI_STATUS_SUCCESS;
}

/* [bool] (default to FALSE) */
sai_status_t mrvl_port_storm_control_get(_In_ const sai_object_key_t   *key,
                                         _Inout_ sai_attribute_value_t *value,
                                         _In_ uint32_t                  attr_index,
                                         _Inout_ vendor_cache_t        *cache,
                                         void                          *arg)
{
    sai_status_t status;
    uint32_t     port_id;

    MRVL_SAI_LOG_ENTER();

    if (SAI_STATUS_SUCCESS != (status = mrvl_object_to_type(key->object_id, SAI_OBJECT_TYPE_PORT, &port_id))) {
        return status;
    }

    value->booldata = false;

    MRVL_SAI_LOG_EXIT();
    return SAI_STATUS_SUCCESS;
}

/* Hardware Lane list [sai_u32_list_t] */
sai_status_t mrvl_port_hw_lanes_get(_In_ const sai_object_key_t   *key,
                                    _Inout_ sai_attribute_value_t *value,
                                    _In_ uint32_t                  attr_index,
                                    _Inout_ vendor_cache_t        *cache,
                                    void                          *arg)
{
    sai_status_t status;
    uint32_t     port_id;

    MRVL_SAI_LOG_ENTER();

    if (SAI_STATUS_SUCCESS != (status = mrvl_object_to_type(key->object_id, SAI_OBJECT_TYPE_PORT, &port_id))) {
        return status;
    }

    MRVL_SAI_LOG_EXIT();
    return SAI_STATUS_SUCCESS;
}

/* Breakout mode(s) supported [sai_s32_list_t] */
sai_status_t mrvl_port_supported_breakout_get(_In_ const sai_object_key_t   *key,
                                              _Inout_ sai_attribute_value_t *value,
                                              _In_ uint32_t                  attr_index,
                                              _Inout_ vendor_cache_t        *cache,
                                              void                          *arg)
{
    sai_status_t status;
    uint32_t     port_id;

    MRVL_SAI_LOG_ENTER();

    if (SAI_STATUS_SUCCESS != (status = mrvl_object_to_type(key->object_id, SAI_OBJECT_TYPE_PORT, &port_id))) {
        return status;
    }

    MRVL_SAI_LOG_EXIT();
    return SAI_STATUS_SUCCESS;
}

/* Current breakout mode [sai_port_breakout_mode_type_t] */
sai_status_t mrvl_port_current_breakout_get(_In_ const sai_object_key_t   *key,
                                            _Inout_ sai_attribute_value_t *value,
                                            _In_ uint32_t                  attr_index,
                                            _Inout_ vendor_cache_t        *cache,
                                            void                          *arg)
{
    sai_status_t status;
    uint32_t     port_id;

    MRVL_SAI_LOG_ENTER();

    if (SAI_STATUS_SUCCESS != (status = mrvl_object_to_type(key->object_id, SAI_OBJECT_TYPE_PORT, &port_id))) {
        return status;
    }

    value->s32 = SAI_PORT_BREAKOUT_MODE_4_LANE;

    MRVL_SAI_LOG_EXIT();
    return SAI_STATUS_SUCCESS;
}

/* Ingress Filtering (Drop Frames with Unknown VLANs) [bool] */
sai_status_t mrvl_port_ingress_filter_get(_In_ const sai_object_key_t   *key,
                                          _Inout_ sai_attribute_value_t *value,
                                          _In_ uint32_t                  attr_index,
                                          _Inout_ vendor_cache_t        *cache,
                                          void                          *arg)
{
    sai_status_t status;
    uint32_t     port_id;

    MRVL_SAI_LOG_ENTER();

    if (SAI_STATUS_SUCCESS != (status = mrvl_object_to_type(key->object_id, SAI_OBJECT_TYPE_PORT, &port_id))) {
        return status;
    }

    value->booldata = false;

    MRVL_SAI_LOG_EXIT();
    return SAI_STATUS_SUCCESS;
}

/* Dropping of untagged frames on ingress [bool] */
/* Dropping of tagged frames on ingress [bool] */
sai_status_t mrvl_port_drop_tags_get(_In_ const sai_object_key_t   *key,
                                     _Inout_ sai_attribute_value_t *value,
                                     _In_ uint32_t                  attr_index,
                                     _Inout_ vendor_cache_t        *cache,
                                     void                          *arg)
{
    sai_status_t status;
    uint32_t     port_id;

    MRVL_SAI_LOG_ENTER();

    assert((SAI_PORT_ATTR_DROP_UNTAGGED == (int64_t)arg) || (SAI_PORT_ATTR_DROP_TAGGED == (int64_t)arg));

    if (SAI_STATUS_SUCCESS != (status = mrvl_object_to_type(key->object_id, SAI_OBJECT_TYPE_PORT, &port_id))) {
        return status;
    }

    value->booldata = false;

    MRVL_SAI_LOG_EXIT();
    return SAI_STATUS_SUCCESS;
}

/* Internal loopback control [sai_port_internal_loopback_mode_t] */
sai_status_t mrvl_port_internal_loopback_get(_In_ const sai_object_key_t   *key,
                                             _Inout_ sai_attribute_value_t *value,
                                             _In_ uint32_t                  attr_index,
                                             _Inout_ vendor_cache_t        *cache,
                                             void                          *arg)
{
    sai_status_t status;
    uint32_t     port_id;

    MRVL_SAI_LOG_ENTER(sai_port_flow_control_mode_t);

    if (SAI_STATUS_SUCCESS != (status = mrvl_object_to_type(key->object_id, SAI_OBJECT_TYPE_PORT, &port_id))) {
        return status;
    }

    value->s32 = SAI_PORT_INTERNAL_LOOPBACK_NONE;

    MRVL_SAI_LOG_EXIT();
    return SAI_STATUS_SUCCESS;
}

/* MTU [uint32_t] */
sai_status_t mrvl_port_mtu_get(_In_ const sai_object_key_t   *key,
                               _Inout_ sai_attribute_value_t *value,
                               _In_ uint32_t                  attr_index,
                               _Inout_ vendor_cache_t        *cache,
                               void                          *arg)
{
    sai_status_t status;
    uint32_t     port_id;

    MRVL_SAI_LOG_ENTER();

    if (SAI_STATUS_SUCCESS != (status = mrvl_object_to_type(key->object_id, SAI_OBJECT_TYPE_PORT, &port_id))) {
        return status;
    }

    value->u32 = 1514;

    MRVL_SAI_LOG_EXIT();
    return SAI_STATUS_SUCCESS;
}
#endif

/**

 * @brief Clear port statistics counters.
 *
 * @param[in] port_id Port id
 * @param[in] number_of_counters Number of counters in the array
 * @param[in] counter_ids Specifies the array of counter ids
 *
 * @return #SAI_STATUS_SUCCESS on success Failure status code on error



 */

sai_status_t mrvl_clear_port_stats(
    _In_ sai_object_id_t port_id,
    _In_ uint32_t number_of_counters,    
    _In_ const sai_port_stat_t *counter_ids
    ){
	MRVL_SAI_LOG_ERR("STUB %s", __func__);
	MRVL_SAI_API_RETURN(SAI_STATUS_STUB);
}


const sai_port_api_t port_api = {
    mrvl_create_port,
    mrvl_remove_port,
    mrvl_set_port_attribute,
    mrvl_get_port_attribute,
    mrvl_get_port_stats,
    mrvl_clear_port_stats,
    mrvl_clear_port_all_stats
};
