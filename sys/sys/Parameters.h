#ifndef _SYS_PARAMS_H_
#define _SYS_PARAMS_H_

// Version of the operating system.
#define LBR_VRS       001
// Future release form.
#define LBR_FRF       002


//////////////////////////
// Systsem limits
#define MAX_USERS     120
#define MAX_GROUPS    200
#define HOSTNAME_LEN  256
#define NOFILE        65536
// Max processes per user.
#define PROC_USERM    1000
// Max threads per process.
#define MAX_PTHREADS  1000
// Max sockets per process.
#define MAX_PSOCKS    1000
//////////////////////////
//////////////////////////
// Blockchain Limits
/////////////////////////
// Max Blockchain Peers
#define MAX_BPEERS   100
// Max inbound peers.
#define MAX_IPEERS   50
// Max outbound peers.
#define MAX_OPEERS   50
////////////////////////////////
// System Default Configuration
////////////////////////////////
// Default User Permissions => 0 = ALL.
#define D_USR_P      0
// Default User Group => 0 = OPERATOR.
#define D_USR_G      0
////////////////////////////////
