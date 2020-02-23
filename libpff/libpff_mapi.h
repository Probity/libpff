/*
 * Message API (MAPI) definitions
 *
 * Copyright (C) 2008-2020, Joachim Metz <joachim.metz@gmail.com>
 *
 * Refer to AUTHORS for acknowledgements.
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */

#if !defined( _LIBPFF_INTERNAL_MAPI_H )
#define _LIBPFF_INTERNAL_MAPI_H

#include <common.h>
#include <types.h>

#ifdef __cplusplus
extern "C" {
#endif

#if !defined( HAVE_LOCAL_LIBPFF )

#include <libpff/mapi.h>

/* Define HAVE_LOCAL_LIBPFF for local use of libpff
 * The definitions in <libpff/mapi.h> are copied here
 * for local use of libpff
 */
#else

/* The attachment methods
 */
enum LIBPFF_ATTACHMENT_METHODS
{
	LIBPFF_ATTACHMENT_METHOD_NONE						= 0,
	LIBPFF_ATTACHMENT_METHOD_BY_VALUE					= 1,
	LIBPFF_ATTACHMENT_METHOD_BY_REFERENCE					= 2,
	LIBPFF_ATTACHMENT_METHOD_BY_REFERENCE_RESOLVE				= 3,
	LIBPFF_ATTACHMENT_METHOD_BY_REFERENCE_ONLY				= 4,
	LIBPFF_ATTACHMENT_METHOD_EMBEDDED_MESSAGE				= 5,
	LIBPFF_ATTACHMENT_METHOD_OLE						= 6
};

/* The message flags
 */
enum LIBPFF_MESSAGE_FLAGS
{
	LIBPFF_MESSAGE_FLAG_READ						= 0x00000001,
	LIBPFF_MESSAGE_FLAG_UNMODIFIED						= 0x00000002,
	LIBPFF_MESSAGE_FLAG_SUBMIT						= 0x00000004,
	LIBPFF_MESSAGE_FLAG_UNSENT						= 0x00000008,
	LIBPFF_MESSAGE_FLAG_HAS_ATTACHMENTS					= 0x00000010,
	LIBPFF_MESSAGE_FLAG_FROM_ME						= 0x00000020,
	LIBPFF_MESSAGE_FLAG_ASSOCIATED						= 0x00000040,
	LIBPFF_MESSAGE_FLAG_RESEND						= 0x00000080,
	LIBPFF_MESSAGE_FLAG_RN_PENDING						= 0x00000100,
	LIBPFF_MESSAGE_FLAG_NRN_PENDING						= 0x00000200
};

/* The message importance types
 */
enum LIBPFF_MESSAGE_IMPORTANCE_TYPES
{
	LIBPFF_MESSAGE_IMPORTANCE_TYPE_LOW					= 0,
	LIBPFF_MESSAGE_IMPORTANCE_TYPE_NORMAL					= 1,
	LIBPFF_MESSAGE_IMPORTANCE_TYPE_HIGH					= 2
};

/* The message priority types
 */
enum LIBPFF_MESSAGE_PRIORITY_TYPES
{
	LIBPFF_MESSAGE_PRIORITY_TYPE_NON_URGENT					= -1,
	LIBPFF_MESSAGE_PRIORITY_TYPE_NORMAL					= 0,
	LIBPFF_MESSAGE_PRIORITY_TYPE_URGENT					= 1
};

/* The message sensitivity types
 */
enum LIBPFF_MESSAGE_SENSITIVITY_TYPES
{
	LIBPFF_MESSAGE_SENSITIVITY_TYPE_NONE					= 0,
	LIBPFF_MESSAGE_SENSITIVITY_TYPE_PERSONAL				= 1,
	LIBPFF_MESSAGE_SENSITIVITY_TYPE_PRIVATE					= 2,
	LIBPFF_MESSAGE_SENSITIVITY_TYPE_CONFIDENTIAL				= 3
};

/* The message status flags
 */
enum LIBPFF_MESSAGE_STATUS_FLAGS
{
	LIBPFF_MESSAGE_STATUS_FLAG_HIGHLIGHTED					= 0x00000001,
	LIBPFF_MESSAGE_STATUS_FLAG_TAGGED					= 0x00000002,
	LIBPFF_MESSAGE_STATUS_FLAG_HIDDEN					= 0x00000004,
	LIBPFF_MESSAGE_STATUS_FLAG_DELETED					= 0x00000008,

	LIBPFF_MESSAGE_STATUS_FLAG_DRAFT					= 0x00000100,
	LIBPFF_MESSAGE_STATUS_FLAG_ANSWERED					= 0x00000200,

	LIBPFF_MESSAGE_STATUS_FLAG_REMOTE_DOWNLOAD				= 0x00001000,
	LIBPFF_MESSAGE_STATUS_FLAG_REMOTE_DELETED				= 0x00002000
};

/* The message store valid folder masks
 */
enum LIBPFF_MESSAGE_STORE_VALID_FOLDER_MASKS
{
	LIBPFF_VALID_FOLDER_MASK_SUBTREE					= 0x00000001,
	LIBPFF_VALID_FOLDER_MASK_INBOX						= 0x00000002,
	LIBPFF_VALID_FOLDER_MASK_OUTBOX						= 0x00000004,
	LIBPFF_VALID_FOLDER_MASK_WASTEBOX					= 0x00000008,
	LIBPFF_VALID_FOLDER_MASK_SENTMAIL					= 0x00000010,
	LIBPFF_VALID_FOLDER_MASK_VIEWS						= 0x00000020,
	LIBPFF_VALID_FOLDER_MASK_COMMON_VIEWS					= 0x00000040,
	LIBPFF_VALID_FOLDER_MASK_FINDER						= 0x00000080
};

/* The object types
 * TODO
enum LIBPFF_OBJECT_TYPES
{
	MAPI_STORE	= 0x00000001,
	MAPI_ADDRBOOK	= 0x00000002,
	MAPI_FOLDER	= 0x00000003,
	MAPI_ABCONT	= 0x00000004,
	MAPI_MESSAGE	= 0x00000005,
	MAPI_MAILUSER	= 0x00000006,
	MAPI_ATTACH	= 0x00000007,
	MAPI_DISTLIST	= 0x00000008,
	MAPI_PROFSECT	= 0x00000009,
	MAPI_STATUS	= 0x0000000a,
	MAPI_SESSION	= 0x0000000b,
	MAPI_FORMINFO	= 0x0000000c
};
 */

/* The recipient type
 */
enum LIBPFF_RECIPIENT_TYPES
{
	LIBPFF_RECIPIENT_TYPE_ORIGINATOR					= 0,
	LIBPFF_RECIPIENT_TYPE_TO						= 1,
	LIBPFF_RECIPIENT_TYPE_CC						= 2,
	LIBPFF_RECIPIENT_TYPE_BCC						= 3
};

/* The value types
 */
enum LIBPFF_VALUE_TYPES
{
	LIBPFF_VALUE_TYPE_UNSPECIFIED						= 0x0000,
	LIBPFF_VALUE_TYPE_NULL							= 0x0001,
	LIBPFF_VALUE_TYPE_INTEGER_16BIT_SIGNED					= 0x0002,
	LIBPFF_VALUE_TYPE_INTEGER_32BIT_SIGNED					= 0x0003,
	LIBPFF_VALUE_TYPE_FLOAT_32BIT						= 0x0004,
	LIBPFF_VALUE_TYPE_DOUBLE_64BIT						= 0x0005,
	LIBPFF_VALUE_TYPE_CURRENCY						= 0x0006,
	LIBPFF_VALUE_TYPE_FLOATINGTIME						= 0x0007,
	LIBPFF_VALUE_TYPE_ERROR							= 0x000a,
	LIBPFF_VALUE_TYPE_BOOLEAN						= 0x000b,
	LIBPFF_VALUE_TYPE_OBJECT						= 0x000d,
	LIBPFF_VALUE_TYPE_INTEGER_64BIT_SIGNED					= 0x0014,
	LIBPFF_VALUE_TYPE_STRING_ASCII						= 0x001e,
	LIBPFF_VALUE_TYPE_STRING_UNICODE					= 0x001f,
	LIBPFF_VALUE_TYPE_FILETIME						= 0x0040,
	LIBPFF_VALUE_TYPE_GUID							= 0x0048,
	LIBPFF_VALUE_TYPE_SERVER_IDENTIFIER					= 0x00fb,
	LIBPFF_VALUE_TYPE_RESTRICTION						= 0x00fd,
	LIBPFF_VALUE_TYPE_RULE_ACTION						= 0x00fe,
	LIBPFF_VALUE_TYPE_BINARY_DATA						= 0x0102,
	LIBPFF_VALUE_TYPE_MULTI_VALUE_INTEGER_16BIT_SIGNED			= 0x1002,
	LIBPFF_VALUE_TYPE_MULTI_VALUE_INTEGER_32BIT_SIGNED			= 0x1003,
	LIBPFF_VALUE_TYPE_MULTI_VALUE_FLOAT_32BIT				= 0x1004,
	LIBPFF_VALUE_TYPE_MULTI_VALUE_DOUBLE_64BIT				= 0x1005,
	LIBPFF_VALUE_TYPE_MULTI_VALUE_CURRENCY					= 0x1006,
	LIBPFF_VALUE_TYPE_MULTI_VALUE_FLOATINGTIME				= 0x1007,
	LIBPFF_VALUE_TYPE_MULTI_VALUE_INTEGER_64BIT_SIGNED			= 0x1014,
	LIBPFF_VALUE_TYPE_MULTI_VALUE_STRING_ASCII				= 0x101e,
	LIBPFF_VALUE_TYPE_MULTI_VALUE_STRING_UNICODE				= 0x101f,
	LIBPFF_VALUE_TYPE_MULTI_VALUE_FILETIME					= 0x1040,
	LIBPFF_VALUE_TYPE_MULTI_VALUE_GUID					= 0x1048,
	LIBPFF_VALUE_TYPE_MULTI_VALUE_BINARY_DATA				= 0x1102
};

#define LIBPFF_VALUE_TYPE_MULTI_VALUE_FLAG					0x1000

#define LIBPFF_VALUE_TYPE_APPLICATION_TIME					LIBPFF_VALUE_TYPE_FLOATINGTIME
#define LIBPFF_VALUE_TYPE_MULTI_VALUE_APPLICATION_TIME				LIBPFF_VALUE_TYPE_MULTI_VALUE_FLOATINGTIME

/* The entry types
 */
enum LIBPFF_ENTRY_TYPES
{
	LIBPFF_ENTRY_TYPE_MESSAGE_IMPORTANCE					= 0x0017,

	LIBPFF_ENTRY_TYPE_MESSAGE_CLASS						= 0x001a,

	LIBPFF_ENTRY_TYPE_MESSAGE_PRIORITY					= 0x0026,

	LIBPFF_ENTRY_TYPE_MESSAGE_SENSITIVITY					= 0x0036,
	LIBPFF_ENTRY_TYPE_MESSAGE_SUBJECT					= 0x0037,

	LIBPFF_ENTRY_TYPE_MESSAGE_CLIENT_SUBMIT_TIME				= 0x0039,

	LIBPFF_ENTRY_TYPE_MESSAGE_SENT_REPRESENTING_SEARCH_KEY			= 0x003b,

	LIBPFF_ENTRY_TYPE_MESSAGE_RECEIVED_BY_ENTRY_IDENTIFIER			= 0x003f,
	LIBPFF_ENTRY_TYPE_MESSAGE_RECEIVED_BY_NAME				= 0x0040,
	LIBPFF_ENTRY_TYPE_MESSAGE_SENT_REPRESENTING_ENTRY_IDENTIFIER		= 0x0041,
	LIBPFF_ENTRY_TYPE_MESSAGE_SENT_REPRESENTING_NAME			= 0x0042,
	LIBPFF_ENTRY_TYPE_MESSAGE_RECEIVED_REPRESENTING_ENTRY_IDENTIFIER	= 0x0043,
	LIBPFF_ENTRY_TYPE_MESSAGE_RECEIVED_REPRESENTING_NAME			= 0x0044,

	LIBPFF_ENTRY_TYPE_MESSAGE_REPLY_RECIPIENT_ENTRIES			= 0x004f,
	LIBPFF_ENTRY_TYPE_MESSAGE_REPLY_RECIPIENT_NAMES				= 0x0050,
	LIBPFF_ENTRY_TYPE_MESSAGE_RECEIVED_BY_SEARCH_KEY			= 0x0051,
	LIBPFF_ENTRY_TYPE_MESSAGE_RECEIVED_REPRESENTING_SEARCH_KEY		= 0x0052,

	LIBPFF_ENTRY_TYPE_MESSAGE_SENT_REPRESENTING_ADDRESS_TYPE		= 0x0064,
	LIBPFF_ENTRY_TYPE_MESSAGE_SENT_REPRESENTING_EMAIL_ADDRESS		= 0x0065,

	LIBPFF_ENTRY_TYPE_MESSAGE_CONVERSATION_TOPIC				= 0x0070,
	LIBPFF_ENTRY_TYPE_MESSAGE_CONVERSATION_INDEX				= 0x0071,

	LIBPFF_ENTRY_TYPE_MESSAGE_RECEIVED_BY_ADDRESS_TYPE			= 0x0075,
	LIBPFF_ENTRY_TYPE_MESSAGE_RECEIVED_BY_EMAIL_ADDRESS			= 0x0076,
	LIBPFF_ENTRY_TYPE_MESSAGE_RECEIVED_REPRESENTING_ADDRESS_TYPE		= 0x0077,
	LIBPFF_ENTRY_TYPE_MESSAGE_RECEIVED_REPRESENTING_EMAIL_ADDRESS		= 0x0078,

	LIBPFF_ENTRY_TYPE_MESSAGE_TRANSPORT_HEADERS				= 0x007d,

	LIBPFF_ENTRY_TYPE_RECIPIENT_TYPE					= 0x0c15,

	LIBPFF_ENTRY_TYPE_MESSAGE_SENDER_ENTRY_IDENTIFIER			= 0x0c19,
	LIBPFF_ENTRY_TYPE_MESSAGE_SENDER_NAME					= 0x0c1a,

	LIBPFF_ENTRY_TYPE_MESSAGE_SENDER_SEARCH_KEY				= 0x0c1d,
	LIBPFF_ENTRY_TYPE_MESSAGE_SENDER_ADDRESS_TYPE				= 0x0c1e,
	LIBPFF_ENTRY_TYPE_MESSAGE_SENDER_EMAIL_ADDRESS				= 0x0c1f,

	LIBPFF_ENTRY_TYPE_MESSAGE_DISPLAY_TO					= 0x0e04,

	LIBPFF_ENTRY_TYPE_MESSAGE_DELIVERY_TIME					= 0x0e06,
	LIBPFF_ENTRY_TYPE_MESSAGE_FLAGS						= 0x0e07,
	LIBPFF_ENTRY_TYPE_MESSAGE_SIZE						= 0x0e08,

	LIBPFF_ENTRY_TYPE_MESSAGE_STATUS					= 0x0e17,

	LIBPFF_ENTRY_TYPE_ATTACHMENT_SIZE					= 0x0e20,

	LIBPFF_ENTRY_TYPE_MESSAGE_INTERNET_ARTICLE_NUMBER			= 0x0e23,

	LIBPFF_ENTRY_TYPE_MESSAGE_PERMISSION					= 0x0e27,

	LIBPFF_ENTRY_TYPE_MESSAGE_URL_COMPUTER_NAME_SET				= 0x0e62,

	LIBPFF_ENTRY_TYPE_MESSAGE_TRUST_SENDER					= 0x0e79,

	LIBPFF_ENTRY_TYPE_MESSAGE_BODY_PLAIN_TEXT				= 0x1000,

	LIBPFF_ENTRY_TYPE_MESSAGE_BODY_COMPRESSED_RTF				= 0x1009,

	LIBPFF_ENTRY_TYPE_MESSAGE_BODY_HTML					= 0x1013,

	LIBPFF_ENTRY_TYPE_EMAIL_EML_FILENAME					= 0x10f3,

	LIBPFF_ENTRY_TYPE_DISPLAY_NAME						= 0x3001,
	LIBPFF_ENTRY_TYPE_ADDRESS_TYPE						= 0x3002,
	LIBPFF_ENTRY_TYPE_EMAIL_ADDRESS						= 0x3003,

	LIBPFF_ENTRY_TYPE_MESSAGE_CREATION_TIME					= 0x3007,
	LIBPFF_ENTRY_TYPE_MESSAGE_MODIFICATION_TIME				= 0x3008,

	LIBPFF_ENTRY_TYPE_MESSAGE_STORE_VALID_FOLDER_MASK			= 0x35df,

	LIBPFF_ENTRY_TYPE_FOLDER_TYPE						= 0x3601,
	LIBPFF_ENTRY_TYPE_NUMBER_OF_CONTENT_ITEMS				= 0x3602,
	LIBPFF_ENTRY_TYPE_NUMBER_OF_UNREAD_CONTENT_ITEMS			= 0x3603,

	LIBPFF_ENTRY_TYPE_HAS_SUB_FOLDERS					= 0x360a,

	LIBPFF_ENTRY_TYPE_CONTAINER_CLASS					= 0x3613,

	LIBPFF_ENTRY_TYPE_NUMBER_OF_ASSOCIATED_CONTENT				= 0x3617,

	LIBPFF_ENTRY_TYPE_ATTACHMENT_DATA_OBJECT				= 0x3701,

	LIBPFF_ENTRY_TYPE_ATTACHMENT_FILENAME_SHORT				= 0x3704,
	LIBPFF_ENTRY_TYPE_ATTACHMENT_METHOD					= 0x3705,

	LIBPFF_ENTRY_TYPE_ATTACHMENT_FILENAME_LONG				= 0x3707,

	LIBPFF_ENTRY_TYPE_ATTACHMENT_RENDERING_POSITION				= 0x370b,

	LIBPFF_ENTRY_TYPE_CONTACT_CALLBACK_PHONE_NUMBER				= 0x3a02,

	LIBPFF_ENTRY_TYPE_CONTACT_GENERATIONAL_ABBREVIATION			= 0x3a05,
	LIBPFF_ENTRY_TYPE_CONTACT_GIVEN_NAME					= 0x3a06,

	LIBPFF_ENTRY_TYPE_CONTACT_BUSINESS_PHONE_NUMBER_1			= 0x3a08,
	LIBPFF_ENTRY_TYPE_CONTACT_HOME_PHONE_NUMBER				= 0x3a09,
	LIBPFF_ENTRY_TYPE_CONTACT_INITIALS					= 0x3a0a,

	LIBPFF_ENTRY_TYPE_CONTACT_SURNAME					= 0x3a11,

	LIBPFF_ENTRY_TYPE_CONTACT_POSTAL_ADDRESS				= 0x3a15,
	LIBPFF_ENTRY_TYPE_CONTACT_COMPANY_NAME					= 0x3a16,
	LIBPFF_ENTRY_TYPE_CONTACT_JOB_TITLE					= 0x3a17,
	LIBPFF_ENTRY_TYPE_CONTACT_DEPARTMENT_NAME				= 0x3a18,
	LIBPFF_ENTRY_TYPE_CONTACT_OFFICE_LOCATION				= 0x3a19,
	LIBPFF_ENTRY_TYPE_CONTACT_PRIMARY_PHONE_NUMBER				= 0x3a1a,
	LIBPFF_ENTRY_TYPE_CONTACT_BUSINESS_PHONE_NUMBER_2			= 0x3a1b,
	LIBPFF_ENTRY_TYPE_CONTACT_MOBILE_PHONE_NUMBER				= 0x3a1c,

	LIBPFF_ENTRY_TYPE_CONTACT_BUSINESS_FAX_NUMBER				= 0x3a24,

	LIBPFF_ENTRY_TYPE_CONTACT_COUNTRY					= 0x3a26,
	LIBPFF_ENTRY_TYPE_CONTACT_LOCALITY					= 0x3a27,

	LIBPFF_ENTRY_TYPE_CONTACT_TITLE						= 0x3a45,

	LIBPFF_ENTRY_TYPE_MESSAGE_BODY_CODEPAGE					= 0x3fde,

	LIBPFF_ENTRY_TYPE_MESSAGE_CODEPAGE					= 0x3ffd,

	LIBPFF_ENTRY_TYPE_RECIPIENT_DISPLAY_NAME				= 0x5ff6,

	LIBPFF_ENTRY_TYPE_FOLDER_CHILD_COUNT					= 0x6638,

	LIBPFF_ENTRY_TYPE_SUB_ITEM_IDENTIFIER					= 0x67f2,

	LIBPFF_ENTRY_TYPE_MESSAGE_STORE_PASSWORD_CHECKSUM			= 0x67ff,

	LIBPFF_ENTRY_TYPE_ADDRESS_FILE_UNDER					= 0x8005,

	LIBPFF_ENTRY_TYPE_DISTRIBUTION_LIST_NAME				= 0x8053,
	LIBPFF_ENTRY_TYPE_DISTRIBUTION_LIST_MEMBER_ONE_OFF_ENTRY_IDENTIFIERS	= 0x8054,
	LIBPFF_ENTRY_TYPE_DISTRIBUTION_LIST_MEMBER_ENTRY_IDENTIFIERS		= 0x8055,

	LIBPFF_ENTRY_TYPE_CONTACT_EMAIL_ADDRESS_1				= 0x8083,

	LIBPFF_ENTRY_TYPE_CONTACT_EMAIL_ADDRESS_2				= 0x8093,

	LIBPFF_ENTRY_TYPE_CONTACT_EMAIL_ADDRESS_3				= 0x80a3,

	LIBPFF_ENTRY_TYPE_TASK_STATUS						= 0x8101,
	LIBPFF_ENTRY_TYPE_TASK_PERCENTAGE_COMPLETE				= 0x8102,

	LIBPFF_ENTRY_TYPE_TASK_START_DATE					= 0x8104,
	LIBPFF_ENTRY_TYPE_TASK_DUE_DATE						= 0x8105,

	LIBPFF_ENTRY_TYPE_TASK_ACTUAL_EFFORT					= 0x8110,
	LIBPFF_ENTRY_TYPE_TASK_TOTAL_EFFORT					= 0x8111,
	LIBPFF_ENTRY_TYPE_TASK_VERSION						= 0x8112,

	LIBPFF_ENTRY_TYPE_TASK_IS_COMPLETE					= 0x811c,

	LIBPFF_ENTRY_TYPE_TASK_IS_RECURRING					= 0x8126,

	LIBPFF_ENTRY_TYPE_APPOINTMENT_BUSY_STATUS				= 0x8205,

	LIBPFF_ENTRY_TYPE_APPOINTMENT_LOCATION					= 0x8208,

	LIBPFF_ENTRY_TYPE_APPOINTMENT_START_TIME				= 0x820d,
	LIBPFF_ENTRY_TYPE_APPOINTMENT_END_TIME					= 0x820e,

	LIBPFF_ENTRY_TYPE_APPOINTMENT_DURATION					= 0x8213,

	LIBPFF_ENTRY_TYPE_APPOINTMENT_IS_RECURRING				= 0x8223,

	LIBPFF_ENTRY_TYPE_APPOINTMENT_RECURRENCE_PATTERN			= 0x8232,

	LIBPFF_ENTRY_TYPE_APPOINTMENT_TIMEZONE_DESCRIPTION			= 0x8234,
	LIBPFF_ENTRY_TYPE_APPOINTMENT_FIRST_EFFECTIVE_TIME			= 0x8235,
	LIBPFF_ENTRY_TYPE_APPOINTMENT_LAST_EFFECTIVE_TIME			= 0x8236,

	LIBPFF_ENTRY_TYPE_MESSAGE_REMINDER_TIME					= 0x8502,
	LIBPFF_ENTRY_TYPE_MESSAGE_IS_REMINDER					= 0x8503,

	LIBPFF_ENTRY_TYPE_MESSAGE_IS_PRIVATE					= 0x8506,

	LIBPFF_ENTRY_TYPE_MESSAGE_REMINDER_SIGNAL_TIME				= 0x8550
};

#endif /* !defined( HAVE_LOCAL_LIBPFF ) */

#ifdef __cplusplus
}
#endif

#endif /* !defined( _LIBPFF_INTERNAL_MAPI_H ) */

