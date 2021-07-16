
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "subscription_data_sets_1.h"

OpenAPI_subscription_data_sets_1_t *OpenAPI_subscription_data_sets_1_create(
    OpenAPI_access_and_mobility_subscription_data_1_t *am_data,
    OpenAPI_smf_selection_subscription_data_1_t *smf_sel_data,
    OpenAPI_ue_context_in_amf_data_1_t *uec_amf_data,
    OpenAPI_ue_context_in_smf_data_1_t *uec_smf_data,
    OpenAPI_ue_context_in_smsf_data_1_t *uec_smsf_data,
    OpenAPI_sms_subscription_data_1_t *sms_subs_data,
    OpenAPI_list_t *sm_data,
    OpenAPI_trace_data_t *trace_data,
    OpenAPI_sms_management_subscription_data_1_t *sms_mng_data,
    OpenAPI_lcs_privacy_data_1_t *lcs_privacy_data,
    OpenAPI_lcs_mo_data_t *lcs_mo_data,
    OpenAPI_v2x_subscription_data_1_t *v2x_data,
    OpenAPI_lcs_broadcast_assistance_types_data_1_t *lcs_broadcast_assistance_types_data
)
{
    OpenAPI_subscription_data_sets_1_t *subscription_data_sets_1_local_var = OpenAPI_malloc(sizeof(OpenAPI_subscription_data_sets_1_t));
    if (!subscription_data_sets_1_local_var) {
        return NULL;
    }
    subscription_data_sets_1_local_var->am_data = am_data;
    subscription_data_sets_1_local_var->smf_sel_data = smf_sel_data;
    subscription_data_sets_1_local_var->uec_amf_data = uec_amf_data;
    subscription_data_sets_1_local_var->uec_smf_data = uec_smf_data;
    subscription_data_sets_1_local_var->uec_smsf_data = uec_smsf_data;
    subscription_data_sets_1_local_var->sms_subs_data = sms_subs_data;
    subscription_data_sets_1_local_var->sm_data = sm_data;
    subscription_data_sets_1_local_var->trace_data = trace_data;
    subscription_data_sets_1_local_var->sms_mng_data = sms_mng_data;
    subscription_data_sets_1_local_var->lcs_privacy_data = lcs_privacy_data;
    subscription_data_sets_1_local_var->lcs_mo_data = lcs_mo_data;
    subscription_data_sets_1_local_var->v2x_data = v2x_data;
    subscription_data_sets_1_local_var->lcs_broadcast_assistance_types_data = lcs_broadcast_assistance_types_data;

    return subscription_data_sets_1_local_var;
}

void OpenAPI_subscription_data_sets_1_free(OpenAPI_subscription_data_sets_1_t *subscription_data_sets_1)
{
    if (NULL == subscription_data_sets_1) {
        return;
    }
    OpenAPI_lnode_t *node;
    OpenAPI_access_and_mobility_subscription_data_1_free(subscription_data_sets_1->am_data);
    OpenAPI_smf_selection_subscription_data_1_free(subscription_data_sets_1->smf_sel_data);
    OpenAPI_ue_context_in_amf_data_1_free(subscription_data_sets_1->uec_amf_data);
    OpenAPI_ue_context_in_smf_data_1_free(subscription_data_sets_1->uec_smf_data);
    OpenAPI_ue_context_in_smsf_data_1_free(subscription_data_sets_1->uec_smsf_data);
    OpenAPI_sms_subscription_data_1_free(subscription_data_sets_1->sms_subs_data);
    OpenAPI_list_for_each(subscription_data_sets_1->sm_data, node) {
        OpenAPI_session_management_subscription_data_1_free(node->data);
    }
    OpenAPI_list_free(subscription_data_sets_1->sm_data);
    OpenAPI_trace_data_free(subscription_data_sets_1->trace_data);
    OpenAPI_sms_management_subscription_data_1_free(subscription_data_sets_1->sms_mng_data);
    OpenAPI_lcs_privacy_data_1_free(subscription_data_sets_1->lcs_privacy_data);
    OpenAPI_lcs_mo_data_free(subscription_data_sets_1->lcs_mo_data);
    OpenAPI_v2x_subscription_data_1_free(subscription_data_sets_1->v2x_data);
    OpenAPI_lcs_broadcast_assistance_types_data_1_free(subscription_data_sets_1->lcs_broadcast_assistance_types_data);
    ogs_free(subscription_data_sets_1);
}

cJSON *OpenAPI_subscription_data_sets_1_convertToJSON(OpenAPI_subscription_data_sets_1_t *subscription_data_sets_1)
{
    cJSON *item = NULL;

    if (subscription_data_sets_1 == NULL) {
        ogs_error("OpenAPI_subscription_data_sets_1_convertToJSON() failed [SubscriptionDataSets_1]");
        return NULL;
    }

    item = cJSON_CreateObject();
    if (subscription_data_sets_1->am_data) {
    cJSON *am_data_local_JSON = OpenAPI_access_and_mobility_subscription_data_1_convertToJSON(subscription_data_sets_1->am_data);
    if (am_data_local_JSON == NULL) {
        ogs_error("OpenAPI_subscription_data_sets_1_convertToJSON() failed [am_data]");
        goto end;
    }
    cJSON_AddItemToObject(item, "amData", am_data_local_JSON);
    if (item->child == NULL) {
        ogs_error("OpenAPI_subscription_data_sets_1_convertToJSON() failed [am_data]");
        goto end;
    }
    }

    if (subscription_data_sets_1->smf_sel_data) {
    cJSON *smf_sel_data_local_JSON = OpenAPI_smf_selection_subscription_data_1_convertToJSON(subscription_data_sets_1->smf_sel_data);
    if (smf_sel_data_local_JSON == NULL) {
        ogs_error("OpenAPI_subscription_data_sets_1_convertToJSON() failed [smf_sel_data]");
        goto end;
    }
    cJSON_AddItemToObject(item, "smfSelData", smf_sel_data_local_JSON);
    if (item->child == NULL) {
        ogs_error("OpenAPI_subscription_data_sets_1_convertToJSON() failed [smf_sel_data]");
        goto end;
    }
    }

    if (subscription_data_sets_1->uec_amf_data) {
    cJSON *uec_amf_data_local_JSON = OpenAPI_ue_context_in_amf_data_1_convertToJSON(subscription_data_sets_1->uec_amf_data);
    if (uec_amf_data_local_JSON == NULL) {
        ogs_error("OpenAPI_subscription_data_sets_1_convertToJSON() failed [uec_amf_data]");
        goto end;
    }
    cJSON_AddItemToObject(item, "uecAmfData", uec_amf_data_local_JSON);
    if (item->child == NULL) {
        ogs_error("OpenAPI_subscription_data_sets_1_convertToJSON() failed [uec_amf_data]");
        goto end;
    }
    }

    if (subscription_data_sets_1->uec_smf_data) {
    cJSON *uec_smf_data_local_JSON = OpenAPI_ue_context_in_smf_data_1_convertToJSON(subscription_data_sets_1->uec_smf_data);
    if (uec_smf_data_local_JSON == NULL) {
        ogs_error("OpenAPI_subscription_data_sets_1_convertToJSON() failed [uec_smf_data]");
        goto end;
    }
    cJSON_AddItemToObject(item, "uecSmfData", uec_smf_data_local_JSON);
    if (item->child == NULL) {
        ogs_error("OpenAPI_subscription_data_sets_1_convertToJSON() failed [uec_smf_data]");
        goto end;
    }
    }

    if (subscription_data_sets_1->uec_smsf_data) {
    cJSON *uec_smsf_data_local_JSON = OpenAPI_ue_context_in_smsf_data_1_convertToJSON(subscription_data_sets_1->uec_smsf_data);
    if (uec_smsf_data_local_JSON == NULL) {
        ogs_error("OpenAPI_subscription_data_sets_1_convertToJSON() failed [uec_smsf_data]");
        goto end;
    }
    cJSON_AddItemToObject(item, "uecSmsfData", uec_smsf_data_local_JSON);
    if (item->child == NULL) {
        ogs_error("OpenAPI_subscription_data_sets_1_convertToJSON() failed [uec_smsf_data]");
        goto end;
    }
    }

    if (subscription_data_sets_1->sms_subs_data) {
    cJSON *sms_subs_data_local_JSON = OpenAPI_sms_subscription_data_1_convertToJSON(subscription_data_sets_1->sms_subs_data);
    if (sms_subs_data_local_JSON == NULL) {
        ogs_error("OpenAPI_subscription_data_sets_1_convertToJSON() failed [sms_subs_data]");
        goto end;
    }
    cJSON_AddItemToObject(item, "smsSubsData", sms_subs_data_local_JSON);
    if (item->child == NULL) {
        ogs_error("OpenAPI_subscription_data_sets_1_convertToJSON() failed [sms_subs_data]");
        goto end;
    }
    }

    if (subscription_data_sets_1->sm_data) {
    cJSON *sm_dataList = cJSON_AddArrayToObject(item, "smData");
    if (sm_dataList == NULL) {
        ogs_error("OpenAPI_subscription_data_sets_1_convertToJSON() failed [sm_data]");
        goto end;
    }

    OpenAPI_lnode_t *sm_data_node;
    if (subscription_data_sets_1->sm_data) {
        OpenAPI_list_for_each(subscription_data_sets_1->sm_data, sm_data_node) {
            cJSON *itemLocal = OpenAPI_session_management_subscription_data_1_convertToJSON(sm_data_node->data);
            if (itemLocal == NULL) {
                ogs_error("OpenAPI_subscription_data_sets_1_convertToJSON() failed [sm_data]");
                goto end;
            }
            cJSON_AddItemToArray(sm_dataList, itemLocal);
        }
    }
    }

    if (subscription_data_sets_1->trace_data) {
    cJSON *trace_data_local_JSON = OpenAPI_trace_data_convertToJSON(subscription_data_sets_1->trace_data);
    if (trace_data_local_JSON == NULL) {
        ogs_error("OpenAPI_subscription_data_sets_1_convertToJSON() failed [trace_data]");
        goto end;
    }
    cJSON_AddItemToObject(item, "traceData", trace_data_local_JSON);
    if (item->child == NULL) {
        ogs_error("OpenAPI_subscription_data_sets_1_convertToJSON() failed [trace_data]");
        goto end;
    }
    }

    if (subscription_data_sets_1->sms_mng_data) {
    cJSON *sms_mng_data_local_JSON = OpenAPI_sms_management_subscription_data_1_convertToJSON(subscription_data_sets_1->sms_mng_data);
    if (sms_mng_data_local_JSON == NULL) {
        ogs_error("OpenAPI_subscription_data_sets_1_convertToJSON() failed [sms_mng_data]");
        goto end;
    }
    cJSON_AddItemToObject(item, "smsMngData", sms_mng_data_local_JSON);
    if (item->child == NULL) {
        ogs_error("OpenAPI_subscription_data_sets_1_convertToJSON() failed [sms_mng_data]");
        goto end;
    }
    }

    if (subscription_data_sets_1->lcs_privacy_data) {
    cJSON *lcs_privacy_data_local_JSON = OpenAPI_lcs_privacy_data_1_convertToJSON(subscription_data_sets_1->lcs_privacy_data);
    if (lcs_privacy_data_local_JSON == NULL) {
        ogs_error("OpenAPI_subscription_data_sets_1_convertToJSON() failed [lcs_privacy_data]");
        goto end;
    }
    cJSON_AddItemToObject(item, "lcsPrivacyData", lcs_privacy_data_local_JSON);
    if (item->child == NULL) {
        ogs_error("OpenAPI_subscription_data_sets_1_convertToJSON() failed [lcs_privacy_data]");
        goto end;
    }
    }

    if (subscription_data_sets_1->lcs_mo_data) {
    cJSON *lcs_mo_data_local_JSON = OpenAPI_lcs_mo_data_convertToJSON(subscription_data_sets_1->lcs_mo_data);
    if (lcs_mo_data_local_JSON == NULL) {
        ogs_error("OpenAPI_subscription_data_sets_1_convertToJSON() failed [lcs_mo_data]");
        goto end;
    }
    cJSON_AddItemToObject(item, "lcsMoData", lcs_mo_data_local_JSON);
    if (item->child == NULL) {
        ogs_error("OpenAPI_subscription_data_sets_1_convertToJSON() failed [lcs_mo_data]");
        goto end;
    }
    }

    if (subscription_data_sets_1->v2x_data) {
    cJSON *v2x_data_local_JSON = OpenAPI_v2x_subscription_data_1_convertToJSON(subscription_data_sets_1->v2x_data);
    if (v2x_data_local_JSON == NULL) {
        ogs_error("OpenAPI_subscription_data_sets_1_convertToJSON() failed [v2x_data]");
        goto end;
    }
    cJSON_AddItemToObject(item, "v2xData", v2x_data_local_JSON);
    if (item->child == NULL) {
        ogs_error("OpenAPI_subscription_data_sets_1_convertToJSON() failed [v2x_data]");
        goto end;
    }
    }

    if (subscription_data_sets_1->lcs_broadcast_assistance_types_data) {
    cJSON *lcs_broadcast_assistance_types_data_local_JSON = OpenAPI_lcs_broadcast_assistance_types_data_1_convertToJSON(subscription_data_sets_1->lcs_broadcast_assistance_types_data);
    if (lcs_broadcast_assistance_types_data_local_JSON == NULL) {
        ogs_error("OpenAPI_subscription_data_sets_1_convertToJSON() failed [lcs_broadcast_assistance_types_data]");
        goto end;
    }
    cJSON_AddItemToObject(item, "lcsBroadcastAssistanceTypesData", lcs_broadcast_assistance_types_data_local_JSON);
    if (item->child == NULL) {
        ogs_error("OpenAPI_subscription_data_sets_1_convertToJSON() failed [lcs_broadcast_assistance_types_data]");
        goto end;
    }
    }

end:
    return item;
}

OpenAPI_subscription_data_sets_1_t *OpenAPI_subscription_data_sets_1_parseFromJSON(cJSON *subscription_data_sets_1JSON)
{
    OpenAPI_subscription_data_sets_1_t *subscription_data_sets_1_local_var = NULL;
    cJSON *am_data = cJSON_GetObjectItemCaseSensitive(subscription_data_sets_1JSON, "amData");

    OpenAPI_access_and_mobility_subscription_data_1_t *am_data_local_nonprim = NULL;
    if (am_data) {
    am_data_local_nonprim = OpenAPI_access_and_mobility_subscription_data_1_parseFromJSON(am_data);
    }

    cJSON *smf_sel_data = cJSON_GetObjectItemCaseSensitive(subscription_data_sets_1JSON, "smfSelData");

    OpenAPI_smf_selection_subscription_data_1_t *smf_sel_data_local_nonprim = NULL;
    if (smf_sel_data) {
    smf_sel_data_local_nonprim = OpenAPI_smf_selection_subscription_data_1_parseFromJSON(smf_sel_data);
    }

    cJSON *uec_amf_data = cJSON_GetObjectItemCaseSensitive(subscription_data_sets_1JSON, "uecAmfData");

    OpenAPI_ue_context_in_amf_data_1_t *uec_amf_data_local_nonprim = NULL;
    if (uec_amf_data) {
    uec_amf_data_local_nonprim = OpenAPI_ue_context_in_amf_data_1_parseFromJSON(uec_amf_data);
    }

    cJSON *uec_smf_data = cJSON_GetObjectItemCaseSensitive(subscription_data_sets_1JSON, "uecSmfData");

    OpenAPI_ue_context_in_smf_data_1_t *uec_smf_data_local_nonprim = NULL;
    if (uec_smf_data) {
    uec_smf_data_local_nonprim = OpenAPI_ue_context_in_smf_data_1_parseFromJSON(uec_smf_data);
    }

    cJSON *uec_smsf_data = cJSON_GetObjectItemCaseSensitive(subscription_data_sets_1JSON, "uecSmsfData");

    OpenAPI_ue_context_in_smsf_data_1_t *uec_smsf_data_local_nonprim = NULL;
    if (uec_smsf_data) {
    uec_smsf_data_local_nonprim = OpenAPI_ue_context_in_smsf_data_1_parseFromJSON(uec_smsf_data);
    }

    cJSON *sms_subs_data = cJSON_GetObjectItemCaseSensitive(subscription_data_sets_1JSON, "smsSubsData");

    OpenAPI_sms_subscription_data_1_t *sms_subs_data_local_nonprim = NULL;
    if (sms_subs_data) {
    sms_subs_data_local_nonprim = OpenAPI_sms_subscription_data_1_parseFromJSON(sms_subs_data);
    }

    cJSON *sm_data = cJSON_GetObjectItemCaseSensitive(subscription_data_sets_1JSON, "smData");

    OpenAPI_list_t *sm_dataList;
    if (sm_data) {
    cJSON *sm_data_local_nonprimitive;
    if (!cJSON_IsArray(sm_data)){
        ogs_error("OpenAPI_subscription_data_sets_1_parseFromJSON() failed [sm_data]");
        goto end;
    }

    sm_dataList = OpenAPI_list_create();

    cJSON_ArrayForEach(sm_data_local_nonprimitive, sm_data ) {
        if (!cJSON_IsObject(sm_data_local_nonprimitive)) {
            ogs_error("OpenAPI_subscription_data_sets_1_parseFromJSON() failed [sm_data]");
            goto end;
        }
        OpenAPI_session_management_subscription_data_1_t *sm_dataItem = OpenAPI_session_management_subscription_data_1_parseFromJSON(sm_data_local_nonprimitive);

        OpenAPI_list_add(sm_dataList, sm_dataItem);
    }
    }

    cJSON *trace_data = cJSON_GetObjectItemCaseSensitive(subscription_data_sets_1JSON, "traceData");

    OpenAPI_trace_data_t *trace_data_local_nonprim = NULL;
    if (trace_data) {
    trace_data_local_nonprim = OpenAPI_trace_data_parseFromJSON(trace_data);
    }

    cJSON *sms_mng_data = cJSON_GetObjectItemCaseSensitive(subscription_data_sets_1JSON, "smsMngData");

    OpenAPI_sms_management_subscription_data_1_t *sms_mng_data_local_nonprim = NULL;
    if (sms_mng_data) {
    sms_mng_data_local_nonprim = OpenAPI_sms_management_subscription_data_1_parseFromJSON(sms_mng_data);
    }

    cJSON *lcs_privacy_data = cJSON_GetObjectItemCaseSensitive(subscription_data_sets_1JSON, "lcsPrivacyData");

    OpenAPI_lcs_privacy_data_1_t *lcs_privacy_data_local_nonprim = NULL;
    if (lcs_privacy_data) {
    lcs_privacy_data_local_nonprim = OpenAPI_lcs_privacy_data_1_parseFromJSON(lcs_privacy_data);
    }

    cJSON *lcs_mo_data = cJSON_GetObjectItemCaseSensitive(subscription_data_sets_1JSON, "lcsMoData");

    OpenAPI_lcs_mo_data_t *lcs_mo_data_local_nonprim = NULL;
    if (lcs_mo_data) {
    lcs_mo_data_local_nonprim = OpenAPI_lcs_mo_data_parseFromJSON(lcs_mo_data);
    }

    cJSON *v2x_data = cJSON_GetObjectItemCaseSensitive(subscription_data_sets_1JSON, "v2xData");

    OpenAPI_v2x_subscription_data_1_t *v2x_data_local_nonprim = NULL;
    if (v2x_data) {
    v2x_data_local_nonprim = OpenAPI_v2x_subscription_data_1_parseFromJSON(v2x_data);
    }

    cJSON *lcs_broadcast_assistance_types_data = cJSON_GetObjectItemCaseSensitive(subscription_data_sets_1JSON, "lcsBroadcastAssistanceTypesData");

    OpenAPI_lcs_broadcast_assistance_types_data_1_t *lcs_broadcast_assistance_types_data_local_nonprim = NULL;
    if (lcs_broadcast_assistance_types_data) {
    lcs_broadcast_assistance_types_data_local_nonprim = OpenAPI_lcs_broadcast_assistance_types_data_1_parseFromJSON(lcs_broadcast_assistance_types_data);
    }

    subscription_data_sets_1_local_var = OpenAPI_subscription_data_sets_1_create (
        am_data ? am_data_local_nonprim : NULL,
        smf_sel_data ? smf_sel_data_local_nonprim : NULL,
        uec_amf_data ? uec_amf_data_local_nonprim : NULL,
        uec_smf_data ? uec_smf_data_local_nonprim : NULL,
        uec_smsf_data ? uec_smsf_data_local_nonprim : NULL,
        sms_subs_data ? sms_subs_data_local_nonprim : NULL,
        sm_data ? sm_dataList : NULL,
        trace_data ? trace_data_local_nonprim : NULL,
        sms_mng_data ? sms_mng_data_local_nonprim : NULL,
        lcs_privacy_data ? lcs_privacy_data_local_nonprim : NULL,
        lcs_mo_data ? lcs_mo_data_local_nonprim : NULL,
        v2x_data ? v2x_data_local_nonprim : NULL,
        lcs_broadcast_assistance_types_data ? lcs_broadcast_assistance_types_data_local_nonprim : NULL
    );

    return subscription_data_sets_1_local_var;
end:
    return NULL;
}

OpenAPI_subscription_data_sets_1_t *OpenAPI_subscription_data_sets_1_copy(OpenAPI_subscription_data_sets_1_t *dst, OpenAPI_subscription_data_sets_1_t *src)
{
    cJSON *item = NULL;
    char *content = NULL;

    ogs_assert(src);
    item = OpenAPI_subscription_data_sets_1_convertToJSON(src);
    if (!item) {
        ogs_error("OpenAPI_subscription_data_sets_1_convertToJSON() failed");
        return NULL;
    }

    content = cJSON_Print(item);
    cJSON_Delete(item);

    if (!content) {
        ogs_error("cJSON_Print() failed");
        return NULL;
    }

    item = cJSON_Parse(content);
    ogs_free(content);
    if (!item) {
        ogs_error("cJSON_Parse() failed");
        return NULL;
    }

    OpenAPI_subscription_data_sets_1_free(dst);
    dst = OpenAPI_subscription_data_sets_1_parseFromJSON(item);
    cJSON_Delete(item);

    return dst;
}

