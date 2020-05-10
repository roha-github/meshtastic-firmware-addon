/* Automatically generated nanopb header */
/* Generated by nanopb-0.4.1 */

#ifndef PB_MESH_PB_H_INCLUDED
#define PB_MESH_PB_H_INCLUDED
#include <pb.h>

#if PB_PROTO_HEADER_VERSION != 40
#error Regenerate this file with the current version of nanopb generator.
#endif

#ifdef __cplusplus
extern "C" {
#endif

/* Enum definitions */
typedef enum _Constants {
    Constants_Unused = 0
} Constants;

typedef enum _Data_Type {
    Data_Type_OPAQUE = 0,
    Data_Type_CLEAR_TEXT = 1,
    Data_Type_CLEAR_READACK = 2
} Data_Type;

typedef enum _ChannelSettings_ModemConfig {
    ChannelSettings_ModemConfig_Bw125Cr45Sf128 = 0,
    ChannelSettings_ModemConfig_Bw500Cr45Sf128 = 1,
    ChannelSettings_ModemConfig_Bw31_25Cr48Sf512 = 2,
    ChannelSettings_ModemConfig_Bw125Cr48Sf4096 = 3
} ChannelSettings_ModemConfig;

/* Struct definitions */
typedef struct _RouteDiscovery {
    pb_callback_t route;
} RouteDiscovery;

typedef struct _ChannelSettings {
    int32_t tx_power;
    ChannelSettings_ModemConfig modem_config;
    pb_byte_t psk[16];
    char name[12];
} ChannelSettings;

typedef PB_BYTES_ARRAY_T(251) Data_payload_t;
typedef struct _Data {
    Data_Type typ;
    Data_payload_t payload;
} Data;

typedef struct _DebugString {
    char message[256];
} DebugString;

typedef struct _MyNodeInfo {
    int32_t my_node_num;
    bool has_gps;
    int32_t num_channels;
    char region[12];
    char hw_model[16];
    char firmware_version[12];
    uint32_t error_code;
    uint32_t error_address;
    uint32_t error_count;
} MyNodeInfo;

typedef struct _Position {
    int32_t altitude;
    int32_t battery_level;
    uint32_t time;
    int32_t latitude_i;
    int32_t longitude_i;
} Position;

typedef struct _RadioConfig_UserPreferences {
    uint32_t position_broadcast_secs;
    uint32_t send_owner_interval;
    uint32_t num_missed_to_fail;
    uint32_t wait_bluetooth_secs;
    uint32_t screen_on_secs;
    uint32_t phone_timeout_secs;
    uint32_t phone_sds_timeout_sec;
    uint32_t mesh_sds_timeout_secs;
    uint32_t sds_secs;
    uint32_t ls_secs;
    uint32_t min_wake_secs;
    bool keep_all_packets;
    bool promiscuous_mode;
} RadioConfig_UserPreferences;

typedef struct _User {
    char id[16];
    char long_name[40];
    char short_name[5];
    pb_byte_t macaddr[6];
} User;

typedef struct _NodeInfo {
    int32_t num;
    bool has_user;
    User user;
    bool has_position;
    Position position;
    float snr;
} NodeInfo;

typedef struct _RadioConfig {
    bool has_preferences;
    RadioConfig_UserPreferences preferences;
    bool has_channel_settings;
    ChannelSettings channel_settings;
} RadioConfig;

typedef struct _SubPacket {
    bool has_position;
    Position position;
    bool has_data;
    Data data;
    bool has_user;
    User user;
    bool want_response;
} SubPacket;

typedef PB_BYTES_ARRAY_T(256) MeshPacket_encrypted_t;
typedef struct _MeshPacket {
    int32_t from;
    int32_t to;
    pb_size_t which_payload;
    union {
        SubPacket decoded;
        MeshPacket_encrypted_t encrypted;
    };
    uint32_t rx_time;
    uint32_t id;
    float rx_snr;
} MeshPacket;

typedef struct _DeviceState {
    bool has_radio;
    RadioConfig radio;
    bool has_my_node;
    MyNodeInfo my_node;
    bool has_owner;
    User owner;
    pb_size_t node_db_count;
    NodeInfo node_db[32];
    pb_size_t receive_queue_count;
    MeshPacket receive_queue[32];
    bool has_rx_text_message;
    MeshPacket rx_text_message;
    uint32_t version;
} DeviceState;

typedef struct _FromRadio {
    uint32_t num;
    pb_size_t which_variant;
    union {
        MeshPacket packet;
        MyNodeInfo my_info;
        NodeInfo node_info;
        RadioConfig radio;
        DebugString debug_string;
        uint32_t config_complete_id;
        bool rebooted;
    } variant;
} FromRadio;

typedef struct _ToRadio {
    pb_size_t which_variant;
    union {
        MeshPacket packet;
        uint32_t want_config_id;
        RadioConfig set_radio;
        User set_owner;
    } variant;
} ToRadio;


/* Helper constants for enums */
#define _Constants_MIN Constants_Unused
#define _Constants_MAX Constants_Unused
#define _Constants_ARRAYSIZE ((Constants)(Constants_Unused+1))

#define _Data_Type_MIN Data_Type_OPAQUE
#define _Data_Type_MAX Data_Type_CLEAR_READACK
#define _Data_Type_ARRAYSIZE ((Data_Type)(Data_Type_CLEAR_READACK+1))

#define _ChannelSettings_ModemConfig_MIN ChannelSettings_ModemConfig_Bw125Cr45Sf128
#define _ChannelSettings_ModemConfig_MAX ChannelSettings_ModemConfig_Bw125Cr48Sf4096
#define _ChannelSettings_ModemConfig_ARRAYSIZE ((ChannelSettings_ModemConfig)(ChannelSettings_ModemConfig_Bw125Cr48Sf4096+1))


/* Initializer values for message structs */
#define Position_init_default                    {0, 0, 0, 0, 0}
#define Data_init_default                        {_Data_Type_MIN, {0, {0}}}
#define User_init_default                        {"", "", "", {0}}
#define RouteDiscovery_init_default              {{{NULL}, NULL}}
#define SubPacket_init_default                   {false, Position_init_default, false, Data_init_default, false, User_init_default, 0}
#define MeshPacket_init_default                  {0, 0, 0, {SubPacket_init_default}, 0, 0, 0}
#define ChannelSettings_init_default             {0, _ChannelSettings_ModemConfig_MIN, {0}, ""}
#define RadioConfig_init_default                 {false, RadioConfig_UserPreferences_init_default, false, ChannelSettings_init_default}
#define RadioConfig_UserPreferences_init_default {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
#define NodeInfo_init_default                    {0, false, User_init_default, false, Position_init_default, 0}
#define MyNodeInfo_init_default                  {0, 0, 0, "", "", "", 0, 0, 0}
#define DeviceState_init_default                 {false, RadioConfig_init_default, false, MyNodeInfo_init_default, false, User_init_default, 0, {NodeInfo_init_default, NodeInfo_init_default, NodeInfo_init_default, NodeInfo_init_default, NodeInfo_init_default, NodeInfo_init_default, NodeInfo_init_default, NodeInfo_init_default, NodeInfo_init_default, NodeInfo_init_default, NodeInfo_init_default, NodeInfo_init_default, NodeInfo_init_default, NodeInfo_init_default, NodeInfo_init_default, NodeInfo_init_default, NodeInfo_init_default, NodeInfo_init_default, NodeInfo_init_default, NodeInfo_init_default, NodeInfo_init_default, NodeInfo_init_default, NodeInfo_init_default, NodeInfo_init_default, NodeInfo_init_default, NodeInfo_init_default, NodeInfo_init_default, NodeInfo_init_default, NodeInfo_init_default, NodeInfo_init_default, NodeInfo_init_default, NodeInfo_init_default}, 0, {MeshPacket_init_default, MeshPacket_init_default, MeshPacket_init_default, MeshPacket_init_default, MeshPacket_init_default, MeshPacket_init_default, MeshPacket_init_default, MeshPacket_init_default, MeshPacket_init_default, MeshPacket_init_default, MeshPacket_init_default, MeshPacket_init_default, MeshPacket_init_default, MeshPacket_init_default, MeshPacket_init_default, MeshPacket_init_default, MeshPacket_init_default, MeshPacket_init_default, MeshPacket_init_default, MeshPacket_init_default, MeshPacket_init_default, MeshPacket_init_default, MeshPacket_init_default, MeshPacket_init_default, MeshPacket_init_default, MeshPacket_init_default, MeshPacket_init_default, MeshPacket_init_default, MeshPacket_init_default, MeshPacket_init_default, MeshPacket_init_default, MeshPacket_init_default}, false, MeshPacket_init_default, 0}
#define DebugString_init_default                 {""}
#define FromRadio_init_default                   {0, 0, {MeshPacket_init_default}}
#define ToRadio_init_default                     {0, {MeshPacket_init_default}}
#define Position_init_zero                       {0, 0, 0, 0, 0}
#define Data_init_zero                           {_Data_Type_MIN, {0, {0}}}
#define User_init_zero                           {"", "", "", {0}}
#define RouteDiscovery_init_zero                 {{{NULL}, NULL}}
#define SubPacket_init_zero                      {false, Position_init_zero, false, Data_init_zero, false, User_init_zero, 0}
#define MeshPacket_init_zero                     {0, 0, 0, {SubPacket_init_zero}, 0, 0, 0}
#define ChannelSettings_init_zero                {0, _ChannelSettings_ModemConfig_MIN, {0}, ""}
#define RadioConfig_init_zero                    {false, RadioConfig_UserPreferences_init_zero, false, ChannelSettings_init_zero}
#define RadioConfig_UserPreferences_init_zero    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
#define NodeInfo_init_zero                       {0, false, User_init_zero, false, Position_init_zero, 0}
#define MyNodeInfo_init_zero                     {0, 0, 0, "", "", "", 0, 0, 0}
#define DeviceState_init_zero                    {false, RadioConfig_init_zero, false, MyNodeInfo_init_zero, false, User_init_zero, 0, {NodeInfo_init_zero, NodeInfo_init_zero, NodeInfo_init_zero, NodeInfo_init_zero, NodeInfo_init_zero, NodeInfo_init_zero, NodeInfo_init_zero, NodeInfo_init_zero, NodeInfo_init_zero, NodeInfo_init_zero, NodeInfo_init_zero, NodeInfo_init_zero, NodeInfo_init_zero, NodeInfo_init_zero, NodeInfo_init_zero, NodeInfo_init_zero, NodeInfo_init_zero, NodeInfo_init_zero, NodeInfo_init_zero, NodeInfo_init_zero, NodeInfo_init_zero, NodeInfo_init_zero, NodeInfo_init_zero, NodeInfo_init_zero, NodeInfo_init_zero, NodeInfo_init_zero, NodeInfo_init_zero, NodeInfo_init_zero, NodeInfo_init_zero, NodeInfo_init_zero, NodeInfo_init_zero, NodeInfo_init_zero}, 0, {MeshPacket_init_zero, MeshPacket_init_zero, MeshPacket_init_zero, MeshPacket_init_zero, MeshPacket_init_zero, MeshPacket_init_zero, MeshPacket_init_zero, MeshPacket_init_zero, MeshPacket_init_zero, MeshPacket_init_zero, MeshPacket_init_zero, MeshPacket_init_zero, MeshPacket_init_zero, MeshPacket_init_zero, MeshPacket_init_zero, MeshPacket_init_zero, MeshPacket_init_zero, MeshPacket_init_zero, MeshPacket_init_zero, MeshPacket_init_zero, MeshPacket_init_zero, MeshPacket_init_zero, MeshPacket_init_zero, MeshPacket_init_zero, MeshPacket_init_zero, MeshPacket_init_zero, MeshPacket_init_zero, MeshPacket_init_zero, MeshPacket_init_zero, MeshPacket_init_zero, MeshPacket_init_zero, MeshPacket_init_zero}, false, MeshPacket_init_zero, 0}
#define DebugString_init_zero                    {""}
#define FromRadio_init_zero                      {0, 0, {MeshPacket_init_zero}}
#define ToRadio_init_zero                        {0, {MeshPacket_init_zero}}

/* Field tags (for use in manual encoding/decoding) */
#define RouteDiscovery_route_tag                 2
#define ChannelSettings_tx_power_tag             1
#define ChannelSettings_modem_config_tag         3
#define ChannelSettings_psk_tag                  4
#define ChannelSettings_name_tag                 5
#define Data_typ_tag                             1
#define Data_payload_tag                         2
#define DebugString_message_tag                  1
#define MyNodeInfo_my_node_num_tag               1
#define MyNodeInfo_has_gps_tag                   2
#define MyNodeInfo_num_channels_tag              3
#define MyNodeInfo_region_tag                    4
#define MyNodeInfo_hw_model_tag                  5
#define MyNodeInfo_firmware_version_tag          6
#define MyNodeInfo_error_code_tag                7
#define MyNodeInfo_error_address_tag             8
#define MyNodeInfo_error_count_tag               9
#define Position_latitude_i_tag                  7
#define Position_longitude_i_tag                 8
#define Position_altitude_tag                    3
#define Position_battery_level_tag               4
#define Position_time_tag                        6
#define RadioConfig_UserPreferences_position_broadcast_secs_tag 1
#define RadioConfig_UserPreferences_send_owner_interval_tag 2
#define RadioConfig_UserPreferences_num_missed_to_fail_tag 3
#define RadioConfig_UserPreferences_wait_bluetooth_secs_tag 4
#define RadioConfig_UserPreferences_screen_on_secs_tag 5
#define RadioConfig_UserPreferences_phone_timeout_secs_tag 6
#define RadioConfig_UserPreferences_phone_sds_timeout_sec_tag 7
#define RadioConfig_UserPreferences_mesh_sds_timeout_secs_tag 8
#define RadioConfig_UserPreferences_sds_secs_tag 9
#define RadioConfig_UserPreferences_ls_secs_tag  10
#define RadioConfig_UserPreferences_min_wake_secs_tag 11
#define RadioConfig_UserPreferences_keep_all_packets_tag 100
#define RadioConfig_UserPreferences_promiscuous_mode_tag 101
#define User_id_tag                              1
#define User_long_name_tag                       2
#define User_short_name_tag                      3
#define User_macaddr_tag                         4
#define NodeInfo_num_tag                         1
#define NodeInfo_user_tag                        2
#define NodeInfo_position_tag                    3
#define NodeInfo_snr_tag                         7
#define RadioConfig_preferences_tag              1
#define RadioConfig_channel_settings_tag         2
#define SubPacket_position_tag                   1
#define SubPacket_data_tag                       3
#define SubPacket_user_tag                       4
#define SubPacket_want_response_tag              5
#define MeshPacket_decoded_tag                   3
#define MeshPacket_encrypted_tag                 8
#define MeshPacket_from_tag                      1
#define MeshPacket_to_tag                        2
#define MeshPacket_rx_time_tag                   4
#define MeshPacket_id_tag                        6
#define MeshPacket_rx_snr_tag                    7
#define DeviceState_radio_tag                    1
#define DeviceState_my_node_tag                  2
#define DeviceState_owner_tag                    3
#define DeviceState_node_db_tag                  4
#define DeviceState_receive_queue_tag            5
#define DeviceState_version_tag                  8
#define DeviceState_rx_text_message_tag          7
#define FromRadio_packet_tag                     2
#define FromRadio_my_info_tag                    3
#define FromRadio_node_info_tag                  4
#define FromRadio_radio_tag                      6
#define FromRadio_debug_string_tag               7
#define FromRadio_config_complete_id_tag         8
#define FromRadio_rebooted_tag                   9
#define FromRadio_num_tag                        1
#define ToRadio_packet_tag                       1
#define ToRadio_want_config_id_tag               100
#define ToRadio_set_radio_tag                    101
#define ToRadio_set_owner_tag                    102

/* Struct field encoding specification for nanopb */
#define Position_FIELDLIST(X, a) \
X(a, STATIC,   SINGULAR, INT32,    altitude,          3) \
X(a, STATIC,   SINGULAR, INT32,    battery_level,     4) \
X(a, STATIC,   SINGULAR, UINT32,   time,              6) \
X(a, STATIC,   SINGULAR, SINT32,   latitude_i,        7) \
X(a, STATIC,   SINGULAR, SINT32,   longitude_i,       8)
#define Position_CALLBACK NULL
#define Position_DEFAULT NULL

#define Data_FIELDLIST(X, a) \
X(a, STATIC,   SINGULAR, UENUM,    typ,               1) \
X(a, STATIC,   SINGULAR, BYTES,    payload,           2)
#define Data_CALLBACK NULL
#define Data_DEFAULT NULL

#define User_FIELDLIST(X, a) \
X(a, STATIC,   SINGULAR, STRING,   id,                1) \
X(a, STATIC,   SINGULAR, STRING,   long_name,         2) \
X(a, STATIC,   SINGULAR, STRING,   short_name,        3) \
X(a, STATIC,   SINGULAR, FIXED_LENGTH_BYTES, macaddr,           4)
#define User_CALLBACK NULL
#define User_DEFAULT NULL

#define RouteDiscovery_FIELDLIST(X, a) \
X(a, CALLBACK, REPEATED, INT32,    route,             2)
#define RouteDiscovery_CALLBACK pb_default_field_callback
#define RouteDiscovery_DEFAULT NULL

#define SubPacket_FIELDLIST(X, a) \
X(a, STATIC,   OPTIONAL, MESSAGE,  position,          1) \
X(a, STATIC,   OPTIONAL, MESSAGE,  data,              3) \
X(a, STATIC,   OPTIONAL, MESSAGE,  user,              4) \
X(a, STATIC,   SINGULAR, BOOL,     want_response,     5)
#define SubPacket_CALLBACK NULL
#define SubPacket_DEFAULT NULL
#define SubPacket_position_MSGTYPE Position
#define SubPacket_data_MSGTYPE Data
#define SubPacket_user_MSGTYPE User

#define MeshPacket_FIELDLIST(X, a) \
X(a, STATIC,   SINGULAR, INT32,    from,              1) \
X(a, STATIC,   SINGULAR, INT32,    to,                2) \
X(a, STATIC,   ONEOF,    MESSAGE,  (payload,decoded,decoded),   3) \
X(a, STATIC,   ONEOF,    BYTES,    (payload,encrypted,encrypted),   8) \
X(a, STATIC,   SINGULAR, UINT32,   rx_time,           4) \
X(a, STATIC,   SINGULAR, UINT32,   id,                6) \
X(a, STATIC,   SINGULAR, FLOAT,    rx_snr,            7)
#define MeshPacket_CALLBACK NULL
#define MeshPacket_DEFAULT NULL
#define MeshPacket_payload_decoded_MSGTYPE SubPacket

#define ChannelSettings_FIELDLIST(X, a) \
X(a, STATIC,   SINGULAR, INT32,    tx_power,          1) \
X(a, STATIC,   SINGULAR, UENUM,    modem_config,      3) \
X(a, STATIC,   SINGULAR, FIXED_LENGTH_BYTES, psk,               4) \
X(a, STATIC,   SINGULAR, STRING,   name,              5)
#define ChannelSettings_CALLBACK NULL
#define ChannelSettings_DEFAULT NULL

#define RadioConfig_FIELDLIST(X, a) \
X(a, STATIC,   OPTIONAL, MESSAGE,  preferences,       1) \
X(a, STATIC,   OPTIONAL, MESSAGE,  channel_settings,   2)
#define RadioConfig_CALLBACK NULL
#define RadioConfig_DEFAULT NULL
#define RadioConfig_preferences_MSGTYPE RadioConfig_UserPreferences
#define RadioConfig_channel_settings_MSGTYPE ChannelSettings

#define RadioConfig_UserPreferences_FIELDLIST(X, a) \
X(a, STATIC,   SINGULAR, UINT32,   position_broadcast_secs,   1) \
X(a, STATIC,   SINGULAR, UINT32,   send_owner_interval,   2) \
X(a, STATIC,   SINGULAR, UINT32,   num_missed_to_fail,   3) \
X(a, STATIC,   SINGULAR, UINT32,   wait_bluetooth_secs,   4) \
X(a, STATIC,   SINGULAR, UINT32,   screen_on_secs,    5) \
X(a, STATIC,   SINGULAR, UINT32,   phone_timeout_secs,   6) \
X(a, STATIC,   SINGULAR, UINT32,   phone_sds_timeout_sec,   7) \
X(a, STATIC,   SINGULAR, UINT32,   mesh_sds_timeout_secs,   8) \
X(a, STATIC,   SINGULAR, UINT32,   sds_secs,          9) \
X(a, STATIC,   SINGULAR, UINT32,   ls_secs,          10) \
X(a, STATIC,   SINGULAR, UINT32,   min_wake_secs,    11) \
X(a, STATIC,   SINGULAR, BOOL,     keep_all_packets, 100) \
X(a, STATIC,   SINGULAR, BOOL,     promiscuous_mode, 101)
#define RadioConfig_UserPreferences_CALLBACK NULL
#define RadioConfig_UserPreferences_DEFAULT NULL

#define NodeInfo_FIELDLIST(X, a) \
X(a, STATIC,   SINGULAR, INT32,    num,               1) \
X(a, STATIC,   OPTIONAL, MESSAGE,  user,              2) \
X(a, STATIC,   OPTIONAL, MESSAGE,  position,          3) \
X(a, STATIC,   SINGULAR, FLOAT,    snr,               7)
#define NodeInfo_CALLBACK NULL
#define NodeInfo_DEFAULT NULL
#define NodeInfo_user_MSGTYPE User
#define NodeInfo_position_MSGTYPE Position

#define MyNodeInfo_FIELDLIST(X, a) \
X(a, STATIC,   SINGULAR, INT32,    my_node_num,       1) \
X(a, STATIC,   SINGULAR, BOOL,     has_gps,           2) \
X(a, STATIC,   SINGULAR, INT32,    num_channels,      3) \
X(a, STATIC,   SINGULAR, STRING,   region,            4) \
X(a, STATIC,   SINGULAR, STRING,   hw_model,          5) \
X(a, STATIC,   SINGULAR, STRING,   firmware_version,   6) \
X(a, STATIC,   SINGULAR, UINT32,   error_code,        7) \
X(a, STATIC,   SINGULAR, UINT32,   error_address,     8) \
X(a, STATIC,   SINGULAR, UINT32,   error_count,       9)
#define MyNodeInfo_CALLBACK NULL
#define MyNodeInfo_DEFAULT NULL

#define DeviceState_FIELDLIST(X, a) \
X(a, STATIC,   OPTIONAL, MESSAGE,  radio,             1) \
X(a, STATIC,   OPTIONAL, MESSAGE,  my_node,           2) \
X(a, STATIC,   OPTIONAL, MESSAGE,  owner,             3) \
X(a, STATIC,   REPEATED, MESSAGE,  node_db,           4) \
X(a, STATIC,   REPEATED, MESSAGE,  receive_queue,     5) \
X(a, STATIC,   OPTIONAL, MESSAGE,  rx_text_message,   7) \
X(a, STATIC,   SINGULAR, UINT32,   version,           8)
#define DeviceState_CALLBACK NULL
#define DeviceState_DEFAULT NULL
#define DeviceState_radio_MSGTYPE RadioConfig
#define DeviceState_my_node_MSGTYPE MyNodeInfo
#define DeviceState_owner_MSGTYPE User
#define DeviceState_node_db_MSGTYPE NodeInfo
#define DeviceState_receive_queue_MSGTYPE MeshPacket
#define DeviceState_rx_text_message_MSGTYPE MeshPacket

#define DebugString_FIELDLIST(X, a) \
X(a, STATIC,   SINGULAR, STRING,   message,           1)
#define DebugString_CALLBACK NULL
#define DebugString_DEFAULT NULL

#define FromRadio_FIELDLIST(X, a) \
X(a, STATIC,   SINGULAR, UINT32,   num,               1) \
X(a, STATIC,   ONEOF,    MESSAGE,  (variant,packet,variant.packet),   2) \
X(a, STATIC,   ONEOF,    MESSAGE,  (variant,my_info,variant.my_info),   3) \
X(a, STATIC,   ONEOF,    MESSAGE,  (variant,node_info,variant.node_info),   4) \
X(a, STATIC,   ONEOF,    MESSAGE,  (variant,radio,variant.radio),   6) \
X(a, STATIC,   ONEOF,    MESSAGE,  (variant,debug_string,variant.debug_string),   7) \
X(a, STATIC,   ONEOF,    UINT32,   (variant,config_complete_id,variant.config_complete_id),   8) \
X(a, STATIC,   ONEOF,    BOOL,     (variant,rebooted,variant.rebooted),   9)
#define FromRadio_CALLBACK NULL
#define FromRadio_DEFAULT NULL
#define FromRadio_variant_packet_MSGTYPE MeshPacket
#define FromRadio_variant_my_info_MSGTYPE MyNodeInfo
#define FromRadio_variant_node_info_MSGTYPE NodeInfo
#define FromRadio_variant_radio_MSGTYPE RadioConfig
#define FromRadio_variant_debug_string_MSGTYPE DebugString

#define ToRadio_FIELDLIST(X, a) \
X(a, STATIC,   ONEOF,    MESSAGE,  (variant,packet,variant.packet),   1) \
X(a, STATIC,   ONEOF,    UINT32,   (variant,want_config_id,variant.want_config_id), 100) \
X(a, STATIC,   ONEOF,    MESSAGE,  (variant,set_radio,variant.set_radio), 101) \
X(a, STATIC,   ONEOF,    MESSAGE,  (variant,set_owner,variant.set_owner), 102)
#define ToRadio_CALLBACK NULL
#define ToRadio_DEFAULT NULL
#define ToRadio_variant_packet_MSGTYPE MeshPacket
#define ToRadio_variant_set_radio_MSGTYPE RadioConfig
#define ToRadio_variant_set_owner_MSGTYPE User

extern const pb_msgdesc_t Position_msg;
extern const pb_msgdesc_t Data_msg;
extern const pb_msgdesc_t User_msg;
extern const pb_msgdesc_t RouteDiscovery_msg;
extern const pb_msgdesc_t SubPacket_msg;
extern const pb_msgdesc_t MeshPacket_msg;
extern const pb_msgdesc_t ChannelSettings_msg;
extern const pb_msgdesc_t RadioConfig_msg;
extern const pb_msgdesc_t RadioConfig_UserPreferences_msg;
extern const pb_msgdesc_t NodeInfo_msg;
extern const pb_msgdesc_t MyNodeInfo_msg;
extern const pb_msgdesc_t DeviceState_msg;
extern const pb_msgdesc_t DebugString_msg;
extern const pb_msgdesc_t FromRadio_msg;
extern const pb_msgdesc_t ToRadio_msg;

/* Defines for backwards compatibility with code written before nanopb-0.4.0 */
#define Position_fields &Position_msg
#define Data_fields &Data_msg
#define User_fields &User_msg
#define RouteDiscovery_fields &RouteDiscovery_msg
#define SubPacket_fields &SubPacket_msg
#define MeshPacket_fields &MeshPacket_msg
#define ChannelSettings_fields &ChannelSettings_msg
#define RadioConfig_fields &RadioConfig_msg
#define RadioConfig_UserPreferences_fields &RadioConfig_UserPreferences_msg
#define NodeInfo_fields &NodeInfo_msg
#define MyNodeInfo_fields &MyNodeInfo_msg
#define DeviceState_fields &DeviceState_msg
#define DebugString_fields &DebugString_msg
#define FromRadio_fields &FromRadio_msg
#define ToRadio_fields &ToRadio_msg

/* Maximum encoded size of messages (where known) */
#define Position_size                            40
#define Data_size                                256
#define User_size                                72
/* RouteDiscovery_size depends on runtime parameters */
#define SubPacket_size                           377
#define MeshPacket_size                          419
#define ChannelSettings_size                     44
#define RadioConfig_size                         120
#define RadioConfig_UserPreferences_size         72
#define NodeInfo_size                            132
#define MyNodeInfo_size                          85
#define DeviceState_size                         18535
#define DebugString_size                         258
#define FromRadio_size                           428
#define ToRadio_size                             422

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif
