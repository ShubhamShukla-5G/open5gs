#ifndef __PGW_S5C_HANDLER_H__
#define __PGW_S5C_HANDLER_H__

#include "gtp/gtp-message.h"

#include "pgw-context.h"

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

void pgw_s5c_handle_create_session_request(
        pgw_sess_t *sess, gtp_xact_t *xact, gtp_create_session_request_t *req);
void pgw_s5c_handle_delete_session_request(
        pgw_sess_t *sess, gtp_xact_t *xact, gtp_delete_session_request_t *req);
void pgw_s5c_handle_create_bearer_response(
        pgw_sess_t *sess, gtp_xact_t *xact, gtp_create_bearer_response_t *req);
void pgw_s5c_handle_update_bearer_response(
        pgw_sess_t *sess, gtp_xact_t *xact, gtp_update_bearer_response_t *req);
void pgw_s5c_handle_delete_bearer_response(
        pgw_sess_t *sess, gtp_xact_t *xact, gtp_delete_bearer_response_t *req);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* __PGW_S5C_HANDLER_H__ */