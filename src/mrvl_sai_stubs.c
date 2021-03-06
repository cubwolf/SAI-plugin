/*
 *  Copyright (C) 2014. Mellanox Technologies, Ltd. ALL RIGHTS RESERVED.
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
#define __MODULE__ SAI_STUBS

/**
 * @brief Set ingress priority group attribute
 * @param[in] ingress_pg_id ingress priority group id
 * @param[in] attr attribute to set
 *
 * @return  MRVL_SAI_API_RETURN(SAI_STATUS_STUB) on success
 *           Failure status code on error
 */
sai_status_t mrvl_set_ingress_priority_group_attr(_In_ sai_object_id_t ingress_pg_id,_In_ const sai_attribute_t *attr)
{
	MRVL_SAI_LOG_ERR("STUB %s", __func__);
	MRVL_SAI_API_RETURN(SAI_STATUS_STUB);
}

/**
 * @brief Get ingress priority group attributes
 * @param[in] ingress_pg_id ingress priority group id
 * @param[in] attr_count number of attributes
 * @param[inout] attr_list array of attributes
 *
 * @return  MRVL_SAI_API_RETURN(SAI_STATUS_STUB) on success
 *           Failure status code on error
 */
sai_status_t mrvl_get_ingress_priority_group_attr(
    _In_ sai_object_id_t ingress_pg_id,
    _In_ uint32_t attr_count,
    _Inout_ sai_attribute_t *attr_list
    )
{
	MRVL_SAI_LOG_ERR("STUB %s", __func__);
	MRVL_SAI_API_RETURN(SAI_STATUS_STUB);
}
/**
* @brief   Get ingress priority group statistics counters.
*
* @param[in] ingress_pg_id ingress priority group id
* @param[in] counter_ids specifies the array of counter ids
* @param[in] number_of_counters number of counters in the array
* @param[out] counters array of resulting counter values.
*
* @MRVL_SAI_API_RETURN(SAI_STATUS_STUB) on success
*         Failure status code on error
*/
sai_status_t mrvl_get_ingress_priority_group_stats(
    _In_ sai_object_id_t ingress_pg_id,
    _In_ const sai_ingress_priority_group_stat_counter_t *counter_ids,
    _In_ uint32_t number_of_counters,
    _Out_ uint64_t* counters
    )
{
	MRVL_SAI_LOG_ERR("STUB %s", __func__);
	MRVL_SAI_API_RETURN(SAI_STATUS_STUB);
}
/**
* @brief   Clear ingress priority group statistics counters.
*
* @param[in] ingress_pg_id ingress priority group id
* @param[in] counter_ids specifies the array of counter ids
* @param[in] number_of_counters number of counters in the array
*
* @MRVL_SAI_API_RETURN(SAI_STATUS_STUB) on success
*         Failure status code on error
*/
sai_status_t mrvl_clear_ingress_priority_group_stats(
    _In_ sai_object_id_t ingress_pg_id,
    _In_ const sai_ingress_priority_group_stat_counter_t *counter_ids,
    _In_ uint32_t number_of_counters
    )
{
	MRVL_SAI_LOG_ERR("STUB %s", __func__);
	MRVL_SAI_API_RETURN(SAI_STATUS_STUB);
}

/**
 * @brief Create buffer pool
 * @param[out] pool_id buffer pool id
 * @param[in] attr_count number of attributes
 * @param[in] attr_list array of attributes
 * @MRVL_SAI_API_RETURN(SAI_STATUS_STUB) on success
 *           Failure status code on error
 */
sai_status_t mrvl_create_buffer_pool(
    _Out_ sai_object_id_t* pool_id,
    _In_ uint32_t attr_count,
    _In_ const sai_attribute_t *attr_list
    )
{
	MRVL_SAI_LOG_ERR("STUB %s", __func__);
	MRVL_SAI_API_RETURN(SAI_STATUS_STUB);
}
/**
 * @brief Remove buffer pool
 * @param[in] pool_id buffer pool id
 * @MRVL_SAI_API_RETURN(SAI_STATUS_STUB) on success
 *           Failure status code on error
 */
sai_status_t mrvl_remove_buffer_pool(
    _In_ sai_object_id_t pool_id
    )
{
	MRVL_SAI_LOG_ERR("STUB %s", __func__);
	MRVL_SAI_API_RETURN(SAI_STATUS_STUB);
}
/**
 * @brief Set buffer pool attribute
 * @param[in] pool_id buffer pool id
 * @param[in] attr attribute
 * @MRVL_SAI_API_RETURN(SAI_STATUS_STUB) on success
 *           Failure status code on error
 */
sai_status_t mrvl_set_buffer_pool_attr(
    _In_ sai_object_id_t pool_id,
    _In_ const sai_attribute_t *attr
    )
{
	MRVL_SAI_LOG_ERR("STUB %s", __func__);
	MRVL_SAI_API_RETURN(SAI_STATUS_STUB);
}

/**
 * @brief Get buffer pool attributes
 * @param[in] pool_id buffer pool id
 * @param[in] attr_count number of attributes
 * @param[inout] attr_list array of attributes
 * @MRVL_SAI_API_RETURN(SAI_STATUS_STUB) on success
 *           Failure status code on error
 */
sai_status_t mrvl_get_buffer_pool_attr(
    _In_ sai_object_id_t pool_id,
    _In_ uint32_t attr_count,
    _Inout_ sai_attribute_t *attr_list
    )
{
	MRVL_SAI_LOG_ERR("STUB %s", __func__);
	MRVL_SAI_API_RETURN(SAI_STATUS_STUB);
}

/**
* @brief   Get buffer pool statistics counters.
*
* @param[in] pool_id buffer pool id
* @param[in] counter_ids specifies the array of counter ids
* @param[in] number_of_counters number of counters in the array
* @param[out] counters array of resulting counter values.
*
* @MRVL_SAI_API_RETURN(SAI_STATUS_STUB) on success
*         Failure status code on error
*/
sai_status_t mrvl_get_buffer_pool_stats(
    _In_ sai_object_id_t pool_id,
    _In_ const sai_buffer_pool_stat_counter_t *counter_ids,
    _In_ uint32_t number_of_counters,
    _Out_ uint64_t* counters
    )
{
	MRVL_SAI_LOG_ERR("STUB %s", __func__);
	MRVL_SAI_API_RETURN(SAI_STATUS_STUB);
}

/**
 * @brief Create buffer profile
 * @param[out] buffer_profile_id buffer profile id
 * @param[in] attr_count number of attributes
 * @param[in] attr_list array of attributes
 * @MRVL_SAI_API_RETURN(SAI_STATUS_STUB) on success
 *           Failure status code on error
 */
sai_status_t mrvl_create_buffer_profile(
    _Out_ sai_object_id_t* buffer_profile_id,
    _In_ uint32_t attr_count,
    _In_ const sai_attribute_t *attr_list
    )
{
	MRVL_SAI_LOG_ERR("STUB %s", __func__);
	MRVL_SAI_API_RETURN(SAI_STATUS_STUB);
}

/**
 * @brief Remove buffer profile
 * @param[in] buffer_profile_id buffer profile id
 * @MRVL_SAI_API_RETURN(SAI_STATUS_STUB) on success
 *           Failure status code on error
 */
sai_status_t mrvl_remove_buffer_profile(
    _In_ sai_object_id_t buffer_profile_id
)
{
	MRVL_SAI_LOG_ERR("STUB %s", __func__);
	MRVL_SAI_API_RETURN(SAI_STATUS_STUB);
}

/**
 * @brief Set buffer profile attribute
 * @param[in] buffer_profile_id buffer profile id
 * @param[in] attr attribute
 * @MRVL_SAI_API_RETURN(SAI_STATUS_STUB) on success
 *           Failure status code on error
 */
sai_status_t mrvl_set_buffer_profile_attr(
    _In_ sai_object_id_t buffer_profile_id,
    _In_ const sai_attribute_t *attr
    )
{
	MRVL_SAI_API_RETURN(SAI_STATUS_STUB);
}

/**
 * @brief Get buffer profile attributes
 * @param[in] buffer_profile_id buffer profile id
 * @param[in] attr_count number of attributes
 * @param[inout] attr_list array of attributes
 * @MRVL_SAI_API_RETURN(SAI_STATUS_STUB) on success
 *           Failure status code on error
 */
sai_status_t mrvl_get_buffer_profile_attr(
    _In_ sai_object_id_t buffer_profile_id,
    _In_ uint32_t attr_count,
    _Inout_ sai_attribute_t *attr_list
    )
{
	MRVL_SAI_API_RETURN(SAI_STATUS_STUB);
}

const sai_buffer_api_t buffer_api = {
    mrvl_create_buffer_pool,
    mrvl_remove_buffer_pool,
    mrvl_set_buffer_pool_attr,
    mrvl_get_buffer_pool_attr,
    mrvl_get_buffer_pool_stats,
    mrvl_set_ingress_priority_group_attr,
    mrvl_get_ingress_priority_group_attr,
    mrvl_get_ingress_priority_group_stats,
    mrvl_clear_ingress_priority_group_stats,
    mrvl_create_buffer_profile,
    mrvl_remove_buffer_profile,
    mrvl_set_buffer_profile_attr,
    mrvl_get_buffer_profile_attr,
};


/**
 * Routine Description:
 *    @brief Create hash
 *
 * Arguments:
 *    @param[out] hash_id - hash id
 *    @param[in] attr_count - number of attributes
 *    @param[in] attr_list - array of attributes
 *
 * Return Values:
 *    @MRVL_SAI_API_RETURN(SAI_STATUS_STUB) on success
 *            Failure status code on error
 *
 */
sai_status_t mrvl_create_hash(
    _Out_ sai_object_id_t* hash_id,
    _In_ uint32_t attr_count,
    _In_ const sai_attribute_t *attr_list
)
{
	MRVL_SAI_LOG_ERR("STUB %s", __func__);
	MRVL_SAI_API_RETURN(SAI_STATUS_STUB);
}

/**
 * Routine Description:
 *    @brief Remove hash
 *
 * Arguments:
 *    @param[in] hash_id - hash id
 *
 * Return Values:
 *    @MRVL_SAI_API_RETURN(SAI_STATUS_STUB) on success
 *            Failure status code on error
 */
sai_status_t mrvl_remove_hash(
    _In_ sai_object_id_t hash_id
)
{
	MRVL_SAI_LOG_ERR("STUB %s", __func__);
	MRVL_SAI_API_RETURN(SAI_STATUS_STUB);
}

/**
 * Routine Description:
 *    @brief Set hash attribute
 *
 * Arguments:
 *    @param[in] hash_id - hash id
 *    @param[in] attr - attribute
 *
 * Return Values:
 *    @MRVL_SAI_API_RETURN(SAI_STATUS_STUB) on success
 *            Failure status code on error
 */
sai_status_t mrvl_set_hash_attribute(
    _In_ sai_object_id_t hash_id,
    _In_ const sai_attribute_t *attr
)
{
	MRVL_SAI_LOG_ERR("STUB %s", __func__);
	MRVL_SAI_API_RETURN(SAI_STATUS_STUB);
}

/**
 * Routine Description:
 *    @brief Get hash attribute value
 *
 * Arguments:
 *    @param[in] hash_id - hash id
 *    @param[in] attr_count - number of attributes
 *    @param[inout] attrs - array of attributes
 *
 * Return Values:
 *    @MRVL_SAI_API_RETURN(SAI_STATUS_STUB) on success
 *            Failure status code on error
 */
sai_status_t mrvl_get_hash_attribute(
    _In_ sai_object_id_t hash_id,
    _In_ uint32_t attr_count,
    _Inout_ sai_attribute_t *attr_list
)
{
	MRVL_SAI_LOG_ERR("STUB %s", __func__);
	MRVL_SAI_API_RETURN(SAI_STATUS_STUB);
}

/**
 *  @brief hash methods, retrieved via sai_api_query()
 */
const sai_hash_api_t hash_api =
{
    mrvl_create_hash,
    mrvl_remove_hash,
    mrvl_set_hash_attribute,
    mrvl_get_hash_attribute
};

/**
 * @brief Create mirror session.
 *
 * @param[out] session_id Port mirror session id
 * @param[in] attr_count Number of attributes
 * @param[in] attr_list Value of attributes
 * @MRVL_SAI_API_RETURN(SAI_STATUS_STUB) if operation is successful otherwise a different
 *  error code is returned.
 */
sai_status_t mrvl_create_mirror_session(
        _Out_ sai_object_id_t *session_id,
        _In_  uint32_t attr_count,
        _In_  const sai_attribute_t *attr_list)
{
	MRVL_SAI_LOG_ERR("STUB %s", __func__);
	MRVL_SAI_API_RETURN(SAI_STATUS_STUB);
}



/**
 * @brief Remove mirror session.
 *
 * @param[in] session_id Port mirror session id
 * @MRVL_SAI_API_RETURN(SAI_STATUS_STUB) if operation is successful otherwise a different
 *  error code is returned.
 */
sai_status_t mrvl_remove_mirror_session(
        _In_ sai_object_id_t session_id)
{
	MRVL_SAI_LOG_ERR("STUB %s", __func__);
	MRVL_SAI_API_RETURN(SAI_STATUS_STUB);
}


/**
 * @brief Set mirror session attributes.
 *
 * @param[in] session_id Port mirror session id
 * @param[in] attr Value of attribute
 * @MRVL_SAI_API_RETURN(SAI_STATUS_STUB) if operation is successful otherwise a different
 *  error code is returned.
 */
sai_status_t mrvl_set_mirror_session_attribute(
        _In_ sai_object_id_t session_id,
        _In_ const  sai_attribute_t *attr)
{
	MRVL_SAI_LOG_ERR("STUB %s", __func__);
	MRVL_SAI_API_RETURN(SAI_STATUS_STUB);
}


/**
 * @brief Get mirror session attributes.
 *
 * @param[in] session_id Port mirror session id
 * @param[in] attr_count Number of attributes
 * @param[inout] attr_list Value of attribute
 * @MRVL_SAI_API_RETURN(SAI_STATUS_STUB) if operation is successful otherwise a different
 *  error code is returned.
 */
sai_status_t mrvl_get_mirror_session_attribute(
        _In_ sai_object_id_t session_id,
        _In_ uint32_t attr_count,
        _Inout_ sai_attribute_t *attr_list)
{
	MRVL_SAI_LOG_ERR("STUB %s", __func__);
	MRVL_SAI_API_RETURN(SAI_STATUS_STUB);
}



/**
 * @brief MIRROR method table retrieved with sai_api_query()
 */
const sai_mirror_api_t mirror_api=
{
		mrvl_create_mirror_session,
		mrvl_remove_mirror_session,
		mrvl_set_mirror_session_attribute,
		mrvl_get_mirror_session_attribute
};

/**
 * @brief Create Policer
 *
 * @param[out] policer_id - the policer id
 * @param[in] attr_count - number of attributes
 * @param[in] attr_list - array of attributes
 *
 * @MRVL_SAI_API_RETURN(SAI_STATUS_STUB) on success
 *         Failure status code on error
 */
sai_status_t mrvl_create_policer(
    _Out_ sai_object_id_t *policer_id,
    _In_ uint32_t attr_count,
    _In_ const sai_attribute_t *attr_list)
{
	MRVL_SAI_LOG_ERR("STUB %s", __func__);
	MRVL_SAI_API_RETURN(SAI_STATUS_STUB);
}



/**
 * @brief Delete policer
 *
 * @param[in] policer_id - Policer id
 *
 * @return  MRVL_SAI_API_RETURN(SAI_STATUS_STUB) on success
 *          Failure status code on error
 */
sai_status_t mrvl_remove_policer(
    _In_ sai_object_id_t policer_id)
{
	MRVL_SAI_LOG_ERR("STUB %s", __func__);
	MRVL_SAI_API_RETURN(SAI_STATUS_STUB);
}




/**
 * @brief  Set Policer attribute
 *
 * @param[in] policer_id - Policer id
 * @param[in] attr - attribute
 *
 * @MRVL_SAI_API_RETURN(SAI_STATUS_STUB) on success
 *         Failure status code on error
 */
sai_status_t mrvl_set_policer_attribute(
    _In_ sai_object_id_t policer_id,
    _In_ const sai_attribute_t *attr
)
{
	MRVL_SAI_LOG_ERR("STUB %s", __func__);
	MRVL_SAI_API_RETURN(SAI_STATUS_STUB);
}



/**
 * @brief  Get Policer attribute
 *
 * @param[in] policer_id - policer id
 * @param[in] attr_count - number of attributes
 * @param[inout] attr_list - array of attributes
 *
 * @MRVL_SAI_API_RETURN(SAI_STATUS_STUB) on success
 *         Failure status code on error
 */
sai_status_t mrvl_get_policer_attribute(
    _In_ sai_object_id_t policer_id,
    _In_ uint32_t attr_count,
    _Inout_ sai_attribute_t *attr_list
)
{
	MRVL_SAI_LOG_ERR("STUB %s", __func__);
	MRVL_SAI_API_RETURN(SAI_STATUS_STUB);
}


/**
 * @brief  Get Policer Statistics
 *
 * @param[in] policer_id - policer id
 * @param[in] counter_ids - array of counter ids
 * @param[in] number_of_counters - number of counters in the array
 * @param[out] counters - array of resulting counter values.
 *
 * @MRVL_SAI_API_RETURN(SAI_STATUS_STUB) on success
 *         Failure status code on error
 */
sai_status_t mrvl_get_policer_statistics(
    _In_ sai_object_id_t policer_id,
    _In_ const sai_policer_stat_counter_t *counter_ids,
    _In_ uint32_t number_of_counters,
    _Out_ uint64_t* counters
)
{
	MRVL_SAI_LOG_ERR("STUB %s", __func__);
	MRVL_SAI_API_RETURN(SAI_STATUS_STUB);
}

/**
 * @brief Policer methods table retrieved with sai_api_query()
 */
const sai_policer_api_t policer_api=
{
    mrvl_create_policer,
    mrvl_remove_policer,
    mrvl_set_policer_attribute,
    mrvl_get_policer_attribute,
    mrvl_get_policer_statistics
} ;

/**
 * @brief Create Qos Map
 *
 * @param[out] qos_map_id Qos Map Id
 * @param[in] attr_count number of attributes
 * @param[in] attr_list array of attributes
 *
 * @return  MRVL_SAI_API_RETURN(SAI_STATUS_STUB) on success
 *          Failure status code on error
 */
sai_status_t mrvl_create_qos_map(
    _Out_ sai_object_id_t* qos_map_id,
    _In_ uint32_t attr_count,
    _In_ const sai_attribute_t *attr_list
)
{
	MRVL_SAI_LOG_ERR("STUB %s", __func__);
	MRVL_SAI_API_RETURN(SAI_STATUS_STUB);
}

/**
 * @brief Remove Qos Map
 *
 *  @param[in] qos_map_id Qos Map id to be removed.
 *
 *  @return  MRVL_SAI_API_RETURN(SAI_STATUS_STUB) on success
 *           Failure status code on error
 */
sai_status_t mrvl_remove_qos_map (
    _In_  sai_object_id_t   qos_map_id
)
{
	MRVL_SAI_LOG_ERR("STUB %s", __func__);
	MRVL_SAI_API_RETURN(SAI_STATUS_STUB);
}

/**
 * @brief Set attributes for qos map
 *
 * @param[in] qos_map_id Qos Map Id
 * @param[in] attr attribute to set
 *
 * @return  MRVL_SAI_API_RETURN(SAI_STATUS_STUB) on success
 *          Failure status code on error
 */

sai_status_t mrvl_set_qos_map_attribute(
    _In_ sai_object_id_t  qos_map_id,
    _In_ const sai_attribute_t *attr
)
{
	MRVL_SAI_LOG_ERR("STUB %s", __func__);
	MRVL_SAI_API_RETURN(SAI_STATUS_STUB);
}

/**
 * @brief  Get attrbutes of qos map
 *
 * @param[in] qos_map_id  map id
 * @param[in] attr_count  number of attributes
 * @param[inout] attr_list  array of attributes
 *
 * @MRVL_SAI_API_RETURN(SAI_STATUS_STUB) on success
 *        Failure status code on error
 */


sai_status_t mrvl_get_qos_map_attribute(
     _In_ sai_object_id_t   qos_map_id ,
     _In_ uint32_t attr_count,
     _Inout_ sai_attribute_t *attr_list
)
{
	MRVL_SAI_LOG_ERR("STUB %s", __func__);
	MRVL_SAI_API_RETURN(SAI_STATUS_STUB);
}

/**
*  Qos Map methods table retrieved with sai_api_query()
*/
const sai_qos_map_api_t qos_map_api=
{
    mrvl_create_qos_map,
    mrvl_remove_qos_map,
    mrvl_set_qos_map_attribute,
    mrvl_get_qos_map_attribute
};

/**
 * @brief Set attribute to Queue
 * @param[in] queue_id queue id to set the attribute
 * @param[in] attr attribute to set
 *
 * @return  MRVL_SAI_API_RETURN(SAI_STATUS_STUB) on success
 *           Failure status code on error
 */
sai_status_t mrvl_set_queue_attribute(
    _In_ sai_object_id_t queue_id,
    _In_ const sai_attribute_t *attr
)
{
	MRVL_SAI_LOG_ERR("STUB %s", __func__);
	MRVL_SAI_API_RETURN(SAI_STATUS_STUB);
}

/**
 * @brief Get attribute to Queue
 * @param[in] queue_id queue id to set the attribute
 * @param[in] attr_count number of attributes
 * @param[inout] attr_list Array of attributes
 *
 * @return  MRVL_SAI_API_RETURN(SAI_STATUS_STUB) on success
 *           Failure status code on error
 */
sai_status_t mrvl_get_queue_attribute(
    _In_ sai_object_id_t queue_id,
    _In_ uint32_t        attr_count,
    _Inout_ sai_attribute_t *attr_list
)
{
	MRVL_SAI_LOG_ERR("STUB %s", __func__);
	MRVL_SAI_API_RETURN(SAI_STATUS_STUB);
}


/**
 * @brief   Get queue statistics counters.
 *
 * @param[in] queue_id Queue id
 * @param[in] counter_ids specifies the array of counter ids
 * @param[in] number_of_counters number of counters in the array
 * @param[out] counters array of resulting counter values.
 *
 * @MRVL_SAI_API_RETURN(SAI_STATUS_STUB) on success
 *         Failure status code on error
 */
sai_status_t mrvl_get_queue_stats(
    _In_ sai_object_id_t queue_id,
    _In_ const sai_queue_stat_counter_t *counter_ids,
    _In_ uint32_t number_of_counters,
    _Out_ uint64_t* counters
)
{
	MRVL_SAI_LOG_ERR("STUB %s", __func__);
	MRVL_SAI_API_RETURN(SAI_STATUS_STUB);
}

/**
 * @brief   Clear queue statistics counters.
 *
 * @param[in] queue_id Queue id
 * @param[in] counter_ids specifies the array of counter ids
 * @param[in] number_of_counters number of counters in the array
 *
 * @MRVL_SAI_API_RETURN(SAI_STATUS_STUB) on success
 *         Failure status code on error
 */
sai_status_t mrvl_clear_queue_stats(
    _In_ sai_object_id_t queue_id,
    _In_ const sai_queue_stat_counter_t *counter_ids,
    _In_ uint32_t number_of_counters
)
{
	MRVL_SAI_LOG_ERR("STUB %s", __func__);
	MRVL_SAI_API_RETURN(SAI_STATUS_STUB);
}


/**
 *  @brief Qos methods table retrieved with sai_api_query()
 */
const sai_queue_api_t queue_api=
{
    mrvl_set_queue_attribute,
    mrvl_get_queue_attribute,
    mrvl_get_queue_stats,
    mrvl_clear_queue_stats
};

/**
 * @brief Create samplepacket session.
 *
 * @param[out] session_id samplepacket session id
 * @param[in] attr_count Number of attributes
 * @param[in] attr_list Value of attributes
 * @MRVL_SAI_API_RETURN(SAI_STATUS_STUB) if operation is successful otherwise a different
 *  error code is returned.
 */
sai_status_t mrvl_create_samplepacket_session(
        _Out_ sai_object_id_t *session_id,
        _In_ uint32_t attr_count,
        _In_ const sai_attribute_t *attr_list)
{
	MRVL_SAI_LOG_ERR("STUB %s", __func__);
	MRVL_SAI_API_RETURN(SAI_STATUS_STUB);
}




/**
 * @brief Remove samplepacket session.
 *
 * @param[in] session_id samplepacket session id
 * @MRVL_SAI_API_RETURN(SAI_STATUS_STUB) if operation is successful otherwise a different
 *  error code is returned.
 */
sai_status_t mrvl_remove_samplepacket_session(
        _In_ sai_object_id_t session_id)
{
	MRVL_SAI_LOG_ERR("STUB %s", __func__);
	MRVL_SAI_API_RETURN(SAI_STATUS_STUB);
}


/**
 * @brief Set samplepacket session attributes.
 *
 * @param[in] session_id samplepacket session id
 * @param[in] attr Value of attribute
 * @MRVL_SAI_API_RETURN(SAI_STATUS_STUB) if operation is successful otherwise a different
 *  error code is returned.
 */
sai_status_t mrvl_set_samplepacket_attribute(
        _In_ sai_object_id_t session_id,
        _In_ const sai_attribute_t *attr)
{
	MRVL_SAI_LOG_ERR("STUB %s", __func__);
	MRVL_SAI_API_RETURN(SAI_STATUS_STUB);
}


/**
 * @brief Get samplepacket session attributes.
 *
 * @param[in] session_id samplepacket session id
 * @param[in] attr_count Number of attributes
 * @param[inout] attr_list Value of attribute
 * @MRVL_SAI_API_RETURN(SAI_STATUS_STUB) if operation is successful otherwise a different
 *  error code is returned.
 */
sai_status_t mrvl_get_samplepacket_attribute(
        _In_ sai_object_id_t session_id,
        _In_ uint32_t attr_count,
        _Inout_ sai_attribute_t *attr_list)
{
	MRVL_SAI_LOG_ERR("STUB %s", __func__);
	MRVL_SAI_API_RETURN(SAI_STATUS_STUB);
}


/**
 * @brief samplepacket method table retrieved with sai_api_query()
 */
const sai_samplepacket_api_t samplepacket_api=
{
    mrvl_create_samplepacket_session,
    mrvl_remove_samplepacket_session,
    mrvl_set_samplepacket_attribute,
    mrvl_get_samplepacket_attribute
} ;

/**
 * @brief  Create Scheduler Profile
 *
 * @param[out] scheduler_id Scheduler id
 * @param[in] attr_count number of attributes
 * @param[in] attr_list array of attributes
 *
 * @return  MRVL_SAI_API_RETURN(SAI_STATUS_STUB) on success
 *          Failure status code on error
 */
sai_status_t mrvl_create_scheduler_profile(
    _Out_ sai_object_id_t  *scheduler_id,
    _In_ uint32_t attr_count,
    _In_ const sai_attribute_t *attr_list
)
{
	MRVL_SAI_LOG_ERR("STUB %s", __func__);
	MRVL_SAI_API_RETURN(SAI_STATUS_STUB);
}

/**
 * @brief  Remove Scheduler profile
 *
 * @param[in] scheduler_id Scheduler id
 *
 * @return  MRVL_SAI_API_RETURN(SAI_STATUS_STUB) on success
 *          Failure status code on error
 */
sai_status_t mrvl_remove_scheduler_profile(
    _In_ sai_object_id_t scheduler_id
)
{
	MRVL_SAI_LOG_ERR("STUB %s", __func__);
	MRVL_SAI_API_RETURN(SAI_STATUS_STUB);
}


/**
 * @brief  Set Scheduler Attribute
 *
 * @param[in] scheduler_id Scheduler id
 * @param[in] attr attribute to set
 *
 * @return  MRVL_SAI_API_RETURN(SAI_STATUS_STUB) on success
 *          Failure status code on error
 */
sai_status_t mrvl_set_scheduler_attribute(
    _In_ sai_object_id_t scheduler_id,
    _In_ const sai_attribute_t *attr
)
{
	MRVL_SAI_LOG_ERR("STUB %s", __func__);
	MRVL_SAI_API_RETURN(SAI_STATUS_STUB);
}

/**
 * @brief  Get Scheduler attribute
 *
 * @param[in] scheduler_id - scheduler id
 * @param[in] attr_count - number of attributes
 * @param[inout] attr_list - array of attributes
 *
 * @MRVL_SAI_API_RETURN(SAI_STATUS_STUB) on success
 *        Failure status code on error
 */

sai_status_t mrvl_get_scheduler_attribute(
    _In_ sai_object_id_t scheduler_id,
    _In_ uint32_t attr_count,
    _Inout_ sai_attribute_t *attr_list
)
{
	MRVL_SAI_LOG_ERR("STUB %s", __func__);
	MRVL_SAI_API_RETURN(SAI_STATUS_STUB);
}


/**
 * @brief  Scheduler methods table retrieved with sai_api_query()
 */
const sai_scheduler_api_t scheduler_api=
{
    mrvl_create_scheduler_profile,
    mrvl_remove_scheduler_profile,
    mrvl_set_scheduler_attribute,
    mrvl_get_scheduler_attribute
} ;

/**
 * @brief  Create Scheduler group
 *
 * @param[out] scheduler_group_id Scheudler group id
 * @param[in] attr_count number of attributes
 * @param[in] attr_list array of attributes
 *
 * @return  MRVL_SAI_API_RETURN(SAI_STATUS_STUB) on success
 *          Failure status code on error
 */
sai_status_t mrvl_create_scheduler_group(
    _Out_ sai_object_id_t  *scheduler_group_id,
    _In_ uint32_t attr_count,
    _In_ const sai_attribute_t *attr_list
)
{
	MRVL_SAI_LOG_ERR("STUB %s", __func__);
	MRVL_SAI_API_RETURN(SAI_STATUS_STUB);
}

/**
 * @brief  Remove Scheduler group
 *
 * @param[in] scheduler_group_id Scheudler group id
 *
 * @return  MRVL_SAI_API_RETURN(SAI_STATUS_STUB) on success
 *          Failure status code on error
 */
sai_status_t mrvl_remove_scheduler_group(
    _In_ sai_object_id_t scheduler_group_id
)
{
	MRVL_SAI_LOG_ERR("STUB %s", __func__);
	MRVL_SAI_API_RETURN(SAI_STATUS_STUB);
}


/**
 * @brief  Set Scheduler group Attribute
 *
 * @param[in] scheduler_group_id Scheudler group id
 * @param[in] attr attribute to set
 *
 * @return  MRVL_SAI_API_RETURN(SAI_STATUS_STUB) on success
 *          Failure status code on error
 */
sai_status_t mrvl_set_scheduler_group_attribute(
    _In_ sai_object_id_t scheduler_group_id,
    _In_ const sai_attribute_t *attr
)
{
	MRVL_SAI_LOG_ERR("STUB %s", __func__);
	MRVL_SAI_API_RETURN(SAI_STATUS_STUB);
}

/**
 * @brief  Get Scheduler Group attribute
 *
 * @param[in] scheduler_group_id - scheduler group id
 * @param[in] attr_count - number of attributes
 * @param[inout] attr_list - array of attributes
 *
 * @MRVL_SAI_API_RETURN(SAI_STATUS_STUB) on success
 *        Failure status code on error
 */

sai_status_t mrvl_get_scheduler_group_attribute(
    _In_ sai_object_id_t scheduler_group_id,
    _In_ uint32_t attr_count,
    _Inout_ sai_attribute_t *attr_list
)
{
	MRVL_SAI_LOG_ERR("STUB %s", __func__);
	MRVL_SAI_API_RETURN(SAI_STATUS_STUB);
}

/**
 * @brief   Add Child queue/group objects to scheduler group
 *
 * @param[in] scheduler_group_id Scheduler group id.
 * @param[in] child_count number of child count
 * @param[in] child_objects array of child objects
 *
 * @MRVL_SAI_API_RETURN(SAI_STATUS_STUB) on success
 *        Failure status code on error
 */
sai_status_t mrvl_add_child_object_to_group(
    _In_ sai_object_id_t scheduler_group_id,
    _In_ uint32_t        child_count,
    _In_ const sai_object_id_t* child_objects
)
{
	MRVL_SAI_LOG_ERR("STUB %s", __func__);
	MRVL_SAI_API_RETURN(SAI_STATUS_STUB);
}


/**
 * @brief   Remove Child queue/group objects from scheduler group
 *
 * @param[in] scheduler_group_id Scheduler group id.
 * @param[in] child_count number of child count
 * @param[in] child_objects array of child objects
 *
 * @MRVL_SAI_API_RETURN(SAI_STATUS_STUB) on success
 *        Failure status code on error
 */
sai_status_t mrvl_remove_child_object_from_group(
    _In_ sai_object_id_t scheduler_group_id,
    _In_ uint32_t        child_count,
    _In_ const sai_object_id_t* child_objects
)
{
	MRVL_SAI_LOG_ERR("STUB %s", __func__);
	MRVL_SAI_API_RETURN(SAI_STATUS_STUB);
}

/**
 * @brief  Scheduler Group methods table retrieved with sai_api_query()
 */
const sai_scheduler_group_api_t scheduler_group_api=
{
    mrvl_create_scheduler_group,
    mrvl_remove_scheduler_group,
    mrvl_set_scheduler_group_attribute,
    mrvl_get_scheduler_group_attribute,
    mrvl_add_child_object_to_group,
    mrvl_remove_child_object_from_group
} ;

/**
 * @brief Create stp instance with default port state as forwarding.
 *
 * @param[out] stp_id stp instance id
 * @param[in] attr_count Number of attributes
 * @param[in] attr_list Value of attributes
 * @MRVL_SAI_API_RETURN(SAI_STATUS_STUB) if operation is successful otherwise a different
 *  error code is returned.
 */
sai_status_t mrvl_create_stp(
    _Out_ sai_object_id_t *stp_id,
    _In_  uint32_t attr_count,
    _In_  const sai_attribute_t *attr_list
)
{
	MRVL_SAI_LOG_ERR("STUB %s", __func__);
	MRVL_SAI_API_RETURN(SAI_STATUS_STUB);
}



/**
 * @brief Remove stp instance.
 *
 * @param[in] stp_id stp instance id
 * @MRVL_SAI_API_RETURN(SAI_STATUS_STUB) if operation is successful otherwise a different
 *  error code is returned.
 */
sai_status_t mrvl_remove_stp(
    _In_ sai_object_id_t stp_id
)
{
	MRVL_SAI_LOG_ERR("STUB %s", __func__);
	MRVL_SAI_API_RETURN(SAI_STATUS_STUB);
}


/**
 * @brief Update stp state of a port in specified stp instance.
 *
 * @param[in] stp_id stp instance id
 * @param[in] port_id port id
 * @param[in] stp_port_state stp state of the port
 * @MRVL_SAI_API_RETURN(SAI_STATUS_STUB) if operation is successful otherwise a different
 *  error code is returned.
 */
sai_status_t mrvl_set_stp_port_state(
    _In_ sai_object_id_t stp_id,
    _In_ sai_object_id_t port_id,
    _In_ sai_port_stp_port_state_t stp_port_state
)
{
	MRVL_SAI_LOG_ERR("STUB %s", __func__);
	MRVL_SAI_API_RETURN(SAI_STATUS_STUB);
}


/**
 * @brief Retrieve stp state of a port in specified stp instance.
 *
 * @param[in] stp_id stp instance id
 * @param[in] port_id port id
 * @param[out] stp_port_state stp state of the port
 * @MRVL_SAI_API_RETURN(SAI_STATUS_STUB) if operation is successful otherwise a different
 *  error code is returned.
 */
sai_status_t mrvl_get_stp_port_state(
    _In_ sai_object_id_t stp_id,
    _In_ sai_object_id_t port_id,
    _Out_ sai_port_stp_port_state_t  *stp_port_state
)
{
	MRVL_SAI_LOG_ERR("STUB %s", __func__);
	MRVL_SAI_API_RETURN(SAI_STATUS_STUB);
}


/**
 * @brief Set the attribute of STP instance.
 *
 * @param[in] stp_id stp instance id
 * @param[in] attr attribute value
 * @MRVL_SAI_API_RETURN(SAI_STATUS_STUB) if operation is successful otherwise a different
 *  error code is returned.
 */
sai_status_t mrvl_set_stp_attribute(
    _In_ sai_object_id_t stp_id,
    _In_ const sai_attribute_t *attr
)
{
	MRVL_SAI_LOG_ERR("STUB %s", __func__);
	MRVL_SAI_API_RETURN(SAI_STATUS_STUB);
}


/**
 * @brief Get the attribute of STP instance.
 *
 * @param[in] stp_id stp instance id
 * @param[in] attr_count number of the attribute
 * @param[in] attr_list attribute value
 * @MRVL_SAI_API_RETURN(SAI_STATUS_STUB) if operation is successful otherwise a different
 *  error code is returned.
 */
sai_status_t mrvl_get_stp_attribute(
    _In_ sai_object_id_t stp_id,
    _In_ uint32_t attr_count,
    _Inout_ sai_attribute_t *attr_list
)
{
	MRVL_SAI_LOG_ERR("STUB %s", __func__);
	MRVL_SAI_API_RETURN(SAI_STATUS_STUB);
}


/**
 * @brief STP method table retrieved with sai_api_query()
 */
const sai_stp_api_t stp_api=
{
    mrvl_create_stp,
    mrvl_remove_stp,
    mrvl_set_stp_attribute,
    mrvl_get_stp_attribute,
    mrvl_set_stp_port_state,
    mrvl_get_stp_port_state
};

/**
 * @brief Create tunnel Map
 *
 * @param[out] tunnel_map_id tunnel Map Id
 * @param[in] attr_count number of attributes
 * @param[in] attr_list array of attributes
 *
 * @return  MRVL_SAI_API_RETURN(SAI_STATUS_STUB) on success
 *          Failure status code on error
 */
sai_status_t mrvl_create_tunnel_map(
    _Out_ sai_object_id_t* tunnel_map_id,
    _In_ uint32_t attr_count,
    _In_ const sai_attribute_t *attr_list
)
{
	MRVL_SAI_LOG_ERR("STUB %s", __func__);
	MRVL_SAI_API_RETURN(SAI_STATUS_STUB);
}

/**
 * @brief Remove tunnel Map
 *
 *  @param[in] tunnel_map_id tunnel Map id to be removed.
 *
 *  @return  MRVL_SAI_API_RETURN(SAI_STATUS_STUB) on success
 *           Failure status code on error
 */
sai_status_t mrvl_remove_tunnel_map (
    _In_  sai_object_id_t   tunnel_map_id
)
{
	MRVL_SAI_LOG_ERR("STUB %s", __func__);
	MRVL_SAI_API_RETURN(SAI_STATUS_STUB);
}

/**
 * @brief Set attributes for tunnel map
 *
 * @param[in] tunnel_map_id tunnel Map Id
 * @param[in] attr attribute to set
 *
 * @return  MRVL_SAI_API_RETURN(SAI_STATUS_STUB) on success
 *          Failure status code on error
 */
sai_status_t mrvl_set_tunnel_map_attribute(
    _In_ sai_object_id_t  tunnel_map_id,
    _In_ const sai_attribute_t *attr
)
{
	MRVL_SAI_LOG_ERR("STUB %s", __func__);
	MRVL_SAI_API_RETURN(SAI_STATUS_STUB);
}

/**
 * @brief  Get attrbutes of tunnel map
 *
 * @param[in] tunnel_map_id  tunnel map id
 * @param[in] attr_count  number of attributes
 * @param[inout] attr_list  array of attributes
 *
 * @MRVL_SAI_API_RETURN(SAI_STATUS_STUB) on success
 *        Failure status code on error
 */
sai_status_t mrvl_get_tunnel_map_attribute(
    _In_ sai_object_id_t   tunnel_map_id,
    _In_ uint32_t attr_count,
    _Inout_ sai_attribute_t *attr_list
)
{
	MRVL_SAI_LOG_ERR("STUB %s", __func__);
	MRVL_SAI_API_RETURN(SAI_STATUS_STUB);
}


/**
 * Routine Description:
 *    @brief Create tunnel
 *
 * Arguments:
 *    @param[out] tunnel_id - tunnel id
 *    @param[in] attr_count - number of attributes
 *    @param[in] attr_list - array of attributes
 *
 * Return Values:
 *    @MRVL_SAI_API_RETURN(SAI_STATUS_STUB) on success
 *            Failure status code on error
 *
 */
sai_status_t mrvl_create_tunnel(
    _Out_ sai_object_id_t* tunnel_id,
    _In_ uint32_t attr_count,
    _In_ const sai_attribute_t *attr_list
)
{
	MRVL_SAI_LOG_ERR("STUB %s", __func__);
	MRVL_SAI_API_RETURN(SAI_STATUS_STUB);
}

/**
 * Routine Description:
 *    @brief Remove tunnel
 *
 * Arguments:
 *    @param[in] tunnel_id ��� tunnel id
 *
 * Return Values:
 *    @MRVL_SAI_API_RETURN(SAI_STATUS_STUB) on success
 *            Failure status code on error
 */
sai_status_t mrvl_remove_tunnel(
    _In_ sai_object_id_t tunnel_id
)
{
	MRVL_SAI_LOG_ERR("STUB %s", __func__);
	MRVL_SAI_API_RETURN(SAI_STATUS_STUB);
}

/**
 * Routine Description:
 *    @brief Set tunnel attribute
 *
 * Arguments:
 *    @param[in] tunnel_id - tunnel id
 *    @param[in] attr - attribute
 *
 * Return Values:
 *    @MRVL_SAI_API_RETURN(SAI_STATUS_STUB) on success
 *            Failure status code on error
 */
sai_status_t mrvl_set_tunnel_attribute(
    _In_ sai_object_id_t tunnel_id,
    _In_ const sai_attribute_t *attr
)
{
	MRVL_SAI_LOG_ERR("STUB %s", __func__);
	MRVL_SAI_API_RETURN(SAI_STATUS_STUB);
}


/**
 * Routine Description:
 *    @brief Get tunnel attributes
 *
 * Arguments:
 *    @param[in] tunnel _id - tunnel id
 *    @param[in] attr_count - number of attributes
 *    @param[inout] attr_list - array of attributes
 *
 * Return Values:
 *    @MRVL_SAI_API_RETURN(SAI_STATUS_STUB) on success
 *            Failure status code on error
 */
sai_status_t mrvl_get_tunnel_attribute(
    _In_ sai_object_id_t tunnel_id,
    _In_ uint32_t attr_count,
    _Inout_ sai_attribute_t *attr_list
)
{
	MRVL_SAI_LOG_ERR("STUB %s", __func__);
	MRVL_SAI_API_RETURN(SAI_STATUS_STUB);
}

/**
 * Routine Description:
 *    @brief Create tunnel termination table entry
 *
 * Arguments:
 *    @param[out] tunnel_term_table_entry_id - tunnel termination table entry id
 *    @param[in] attr_count - number of attributes
 *    @param[in] attr_list - array of attributes
 *
 * Return Values:
 *    @MRVL_SAI_API_RETURN(SAI_STATUS_STUB) on success
 *            Failure status code on error
 */
sai_status_t mrvl_create_tunnel_term_table_entry(
    _Out_ sai_object_id_t* tunnel_term_table_entry_id,
    _In_ uint32_t attr_count,
    _In_ const sai_attribute_t *attr_list
)
{
	MRVL_SAI_LOG_ERR("STUB %s", __func__);
	MRVL_SAI_API_RETURN(SAI_STATUS_STUB);
}

/**
 * Routine Description:
 *    @brief Remove tunnel termination table entry
 *
 * Arguments:
 *    @param[in] tunnel_term_table_entry_id - tunnel termination table entry id
 *
 * Return Values:
 *    @MRVL_SAI_API_RETURN(SAI_STATUS_STUB) on success
 *            Failure status code on error
 */
sai_status_t mrvl_remove_tunnel_term_table_entry(
    _In_ sai_object_id_t tunnel_term_table_entry_id
)
{
	MRVL_SAI_LOG_ERR("STUB %s", __func__);
	MRVL_SAI_API_RETURN(SAI_STATUS_STUB);
}

/**
 * Routine Description:
 *    @brief Set tunnel termination table entry attribute
 *
 * Arguments:
 *    @param[in] tunnel_term_table_entry_id - tunnel termination table entry id
 *    @param[in] attr - attribute
 *
 * Return Values:
 *    @MRVL_SAI_API_RETURN(SAI_STATUS_STUB) on success
 *            Failure status code on error
 */
sai_status_t mrvl_set_tunnel_term_table_entry_attribute(
    _In_ sai_object_id_t tunnel_term_table_entry_id,
    _In_ const sai_attribute_t *attr
)
{
	MRVL_SAI_LOG_ERR("STUB %s", __func__);
	MRVL_SAI_API_RETURN(SAI_STATUS_STUB);
}


/**
 * Routine Description:
 *    @brief Get tunnel termination table entry attributes
 *
 * Arguments:
 *    @param[in] tunnel_term_table_entry_id - tunnel termination table entry id
 *    @param[in] attr_count - number of attributes
 *    @param[inout] attr_list - array of attributes
 *
 * Return Values:
 *    @MRVL_SAI_API_RETURN(SAI_STATUS_STUB) on success
 *            Failure status code on error
 */
sai_status_t mrvl_get_tunnel_term_table_entry_attribute(
    _In_ sai_object_id_t tunnel_term_table_entry_id,
    _In_ uint32_t attr_count,
    _Inout_ sai_attribute_t *attr_list
)
{
	MRVL_SAI_LOG_ERR("STUB %s", __func__);
	MRVL_SAI_API_RETURN(SAI_STATUS_STUB);
}

/**
 * @brief tunnel methods table retrieved with sai_api_query()
 */
const sai_tunnel_api_t tunnel_api=
{
    mrvl_create_tunnel_map,
    mrvl_remove_tunnel_map,
    mrvl_set_tunnel_map_attribute,
    mrvl_get_tunnel_map_attribute,
    mrvl_create_tunnel,
    mrvl_remove_tunnel,
    mrvl_set_tunnel_attribute,
    mrvl_get_tunnel_attribute,
    mrvl_create_tunnel_term_table_entry,
    mrvl_remove_tunnel_term_table_entry,
    mrvl_set_tunnel_term_table_entry_attribute,
    mrvl_get_tunnel_term_table_entry_attribute
} ;

/**
 * Routine Description:
 *    @brief Create UDF
 *
 * Arguments:
 *    @param[out] udf_id - UDF id
 *    @param[in] attr_count - number of attributes
 *    @param[in] attr_list - array of attributes
 *
 * Return Values:
 *    @MRVL_SAI_API_RETURN(SAI_STATUS_STUB) on success
 *            Failure status code on error
 *
 */
sai_status_t mrvl_create_udf(
    _Out_ sai_object_id_t* udf_id,
    _In_ uint32_t attr_count,
    _In_ const sai_attribute_t *attr_list
)
{
	MRVL_SAI_LOG_ERR("STUB %s", __func__);
	MRVL_SAI_API_RETURN(SAI_STATUS_STUB);
}

/**
 * Routine Description:
 *    @brief Remove UDF
 *
 * Arguments:
 *    @param[in] udf_id - UDF id
 *
 * Return Values:
 *    @MRVL_SAI_API_RETURN(SAI_STATUS_STUB) on success
 *            Failure status code on error
 */
sai_status_t mrvl_remove_udf(
    _In_ sai_object_id_t udf_id
)
{
	MRVL_SAI_LOG_ERR("STUB %s", __func__);
	MRVL_SAI_API_RETURN(SAI_STATUS_STUB);
}

/**
 * Routine Description:
 *    @brief Set UDF attribute
 *
 * Arguments:
 *    @param[in] udf_id - UDF id
 *    @param[in] attr - attribute
 *
 * Return Values:
 *    @MRVL_SAI_API_RETURN(SAI_STATUS_STUB) on success
 *            Failure status code on error
 */
sai_status_t mrvl_set_udf_attribute(
    _In_ sai_object_id_t udf_id,
    _In_ const sai_attribute_t *attr
)
{
	MRVL_SAI_LOG_ERR("STUB %s", __func__);
	MRVL_SAI_API_RETURN(SAI_STATUS_STUB);
}

/**
 * Routine Description:
 *    @brief Get UDF attribute value
 *
 * Arguments:
 *    @param[in] udf_id - UDF id
 *    @param[in] attr_count - number of attributes
 *    @param[inout] attrs - array of attributes
 *
 * Return Values:
 *    @MRVL_SAI_API_RETURN(SAI_STATUS_STUB) on success
 *            Failure status code on error
 */
sai_status_t mrvl_get_udf_attribute(
    _In_ sai_object_id_t udf_id,
    _In_ uint32_t attr_count,
    _Inout_ sai_attribute_t *attr_list
)
{
	MRVL_SAI_LOG_ERR("STUB %s", __func__);
	MRVL_SAI_API_RETURN(SAI_STATUS_STUB);
}

/**
 * Routine Description:
 *    @brief Create UDF match
 *
 * Arguments:
 *    @param[out] udf_match_id - UDF match id
 *    @param[in] attr_count - number of attributes
 *    @param[in] attr_list - array of attributes
 *
 * Return Values:
 *    @MRVL_SAI_API_RETURN(SAI_STATUS_STUB) on success
 *            Failure status code on error
 *
 */
sai_status_t mrvl_create_udf_match(
    _Out_ sai_object_id_t* udf_match_id,
    _In_ uint32_t attr_count,
    _In_ const sai_attribute_t *attr_list
)
{
	MRVL_SAI_LOG_ERR("STUB %s", __func__);
	MRVL_SAI_API_RETURN(SAI_STATUS_STUB);
}

/**
 * Routine Description:
 *    @brief Remove UDF match
 *
 * Arguments:
 *    @param[in] udf_match_id - UDF match id
 *
 * Return Values:
 *    @MRVL_SAI_API_RETURN(SAI_STATUS_STUB) on success
 *            Failure status code on error
 */
sai_status_t mrvl_remove_udf_match(
    _In_ sai_object_id_t udf_match_id
)
{
	MRVL_SAI_LOG_ERR("STUB %s", __func__);
	MRVL_SAI_API_RETURN(SAI_STATUS_STUB);
}

/**
 * Routine Description:
 *    @brief Set UDF match attribute
 *
 * Arguments:
 *    @param[in] udf_match_id - UDF match id
 *    @param[in] attr - attribute
 *
 * Return Values:
 *    @MRVL_SAI_API_RETURN(SAI_STATUS_STUB) on success
 *            Failure status code on error
 */
sai_status_t mrvl_set_udf_match_attribute(
    _In_ sai_object_id_t udf_match_id,
    _In_ const sai_attribute_t *attr
)
{
	MRVL_SAI_LOG_ERR("STUB %s", __func__);
	MRVL_SAI_API_RETURN(SAI_STATUS_STUB);
}

/**
 * Routine Description:
 *    @brief Get UDF match attribute value
 *
 * Arguments:
 *    @param[in] udf_match_id - UDF match id
 *    @param[in] attr_count - number of attributes
 *    @param[inout] attrs - array of attributes
 *
 * Return Values:
 *    @MRVL_SAI_API_RETURN(SAI_STATUS_STUB) on success
 *            Failure status code on error
 */
sai_status_t mrvl_get_udf_match_attribute(
    _In_ sai_object_id_t udf_match_id,
    _In_ uint32_t attr_count,
    _Inout_ sai_attribute_t *attr_list
)
{
	MRVL_SAI_LOG_ERR("STUB %s", __func__);
	MRVL_SAI_API_RETURN(SAI_STATUS_STUB);
}

/**
 * Routine Description:
 *    @brief Create UDF group
 *
 * Arguments:
 *    @param[out] udf_group_id - UDF group id
 *    @param[in] attr_count - number of attributes
 *    @param[in] attr_list - array of attributes
 *
 * Return Values:
 *    @MRVL_SAI_API_RETURN(SAI_STATUS_STUB) on success
 *            Failure status code on error
 *
 */
sai_status_t mrvl_create_udf_group(
    _Out_ sai_object_id_t* udf_group_id,
    _In_ uint32_t attr_count,
    _In_ const sai_attribute_t *attr_list
)
{
	MRVL_SAI_LOG_ERR("STUB %s", __func__);
	MRVL_SAI_API_RETURN(SAI_STATUS_STUB);
}

/**
 * Routine Description:
 *    @brief Remove UDF group
 *
 * Arguments:
 *    @param[in] udf_group_id - UDF group id
 *
 * Return Values:
 *    @MRVL_SAI_API_RETURN(SAI_STATUS_STUB) on success
 *            Failure status code on error
 */
sai_status_t mrvl_remove_udf_group(
    _In_ sai_object_id_t udf_group_id
)
{
	MRVL_SAI_LOG_ERR("STUB %s", __func__);
	MRVL_SAI_API_RETURN(SAI_STATUS_STUB);
}

/**
 * Routine Description:
 *    @brief Set UDF group attribute
 *
 * Arguments:
 *    @param[in] udf_group_id - UDF group id
 *    @param[in] attr - attribute
 *
 * Return Values:
 *    @MRVL_SAI_API_RETURN(SAI_STATUS_STUB) on success
 *            Failure status code on error
 */
sai_status_t mrvl_set_udf_group_attribute(
    _In_ sai_object_id_t udf_group_id,
    _In_ const sai_attribute_t *attr
)
{
	MRVL_SAI_LOG_ERR("STUB %s", __func__);
	MRVL_SAI_API_RETURN(SAI_STATUS_STUB);
}

/**
 * Routine Description:
 *    @brief Get UDF group attribute value
 *
 * Arguments:
 *    @param[in] udf_group_id - UDF group id
 *    @param[in] attr_count - number of attributes
 *    @param[inout] attrs - array of attributes
 *
 * Return Values:
 *    @MRVL_SAI_API_RETURN(SAI_STATUS_STUB) on success
 *            Failure status code on error
 */
sai_status_t mrvl_get_udf_group_attribute(
    _In_ sai_object_id_t udf_group_id,
    _In_ uint32_t attr_count,
    _Inout_ sai_attribute_t *attr_list
)
{
	MRVL_SAI_LOG_ERR("STUB %s", __func__);
	MRVL_SAI_API_RETURN(SAI_STATUS_STUB);
}

/**
 *  @brief UDF methods, retrieved via sai_api_query()
 */
const sai_udf_api_t udf_api=
{
    mrvl_create_udf,
    mrvl_remove_udf,
    mrvl_set_udf_attribute,
    mrvl_get_udf_attribute,
    mrvl_create_udf_match,
    mrvl_remove_udf_match,
    mrvl_set_udf_match_attribute,
    mrvl_get_udf_match_attribute,
    mrvl_create_udf_group,
    mrvl_remove_udf_group,
    mrvl_set_udf_group_attribute,
    mrvl_get_udf_group_attribute
} ;

/**
 * @brief Create WRED Profile
 *
 * @param[out] wred_id - Wred profile Id.
 * @param[in] attr_count - number of attributes
 * @param[in] attr_list - array of attributes
 *
 *
 * @MRVL_SAI_API_RETURN(SAI_STATUS_STUB) on success
 *         Failure status code on error
 */

sai_status_t mrvl_create_wred_profile(
    _Out_ sai_object_id_t *wred_id,
    _In_ uint32_t attr_count,
    _In_ const sai_attribute_t *attr_list
)
{
	MRVL_SAI_LOG_ERR("STUB %s", __func__);
	MRVL_SAI_API_RETURN(SAI_STATUS_STUB);
}

/**
 * @brief Remove WRED Profile
 *
 * @param[in] wred_id Wred profile Id.
 *
 * @MRVL_SAI_API_RETURN(SAI_STATUS_STUB) on success
 *         Failure status code on error
 */
sai_status_t mrvl_remove_wred_profile(
    _In_ sai_object_id_t  wred_id
)
{
	MRVL_SAI_LOG_ERR("STUB %s", __func__);
	MRVL_SAI_API_RETURN(SAI_STATUS_STUB);
}


/**
 * @brief Set attributes to Wred profile.
 *
 * @param[out] wred_id Wred profile Id.
 * @param[in] attr attribute
 *
 *
 * @MRVL_SAI_API_RETURN(SAI_STATUS_STUB) on success
 *         Failure status code on error
 */

sai_status_t mrvl_set_wred_attribute(
    _In_ sai_object_id_t wred_id,
    _In_ const sai_attribute_t *attr
)
{
	MRVL_SAI_LOG_ERR("STUB %s", __func__);
	MRVL_SAI_API_RETURN(SAI_STATUS_STUB);
}

/**
 * @brief  Get Wred profile attribute
 *
 * @param[in] wred_id Wred Profile Id
 * @param[in] attr_count number of attributes
 * @param[inout] attr_list  array of attributes
 *
 * @MRVL_SAI_API_RETURN(SAI_STATUS_STUB) on success
 *        Failure status code on error
 */
sai_status_t mrvl_get_wred_attribute(
    _In_ sai_object_id_t wred_id,
    _In_ uint32_t attr_count,
    _Inout_ sai_attribute_t *attr_list
   )
{
	MRVL_SAI_LOG_ERR("STUB %s", __func__);
	MRVL_SAI_API_RETURN(SAI_STATUS_STUB);
}

/**
 * @brief WRED methods table retrieved with sai_api_query()
 */
const sai_wred_api_t wred_api=
{
    mrvl_create_wred_profile,
    mrvl_remove_wred_profile,
    mrvl_set_wred_attribute,
    mrvl_get_wred_attribute
} ;






