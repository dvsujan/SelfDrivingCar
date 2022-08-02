// convert the above code to work on windows instead of linux

#ifndef CLIENT_HPP
#define CLIENT_HPP

// Undefine any conflicting windows.h symbols
// If defined, the following flags inhibit definition of the indicated items.
#define NOGDICAPMASKS     // CC_*, LC_*, PC_*, CP_*, TC_*, RC_
#define NOVIRTUALKEYCODES // VK_*
#define NOWINMESSAGES     // WM_*, EM_*, LB_*, CB_*
#define NOWINSTYLES       // WS_*, CS_*, ES_*, LBS_*, SBS_*, CBS_*
#define NOSYSMETRICS      // SM_*
#define NOMENUS           // MF_*
#define NOICONS           // IDI_*
#define NOKEYSTATES       // MK_*
#define NOSYSCOMMANDS     // SC_*
#define NORASTEROPS       // Binary and Tertiary raster ops
#define NOSHOWWINDOW      // SW_*
#define OEMRESOURCE       // OEM Resource values
#define NOATOM            // Atom Manager routines
#define NOCLIPBOARD       // Clipboard routines
#define NOCOLOR           // Screen colors
#define NOCTLMGR          // Control and Dialog routines
#define NODRAWTEXT        // DrawText() and DT_*
#define NOGDI             // All GDI defines and routines
#define NOKERNEL          // All KERNEL defines and routines
#define NOUSER            // All USER defines and routines
#define NONLS             // All NLS defines and routines
#define NOMB              // MB_* and MessageBox()
#define NOMEMMGR          // GMEM_*, LMEM_*, GHND, LHND, associated routines
#define NOMETAFILE        // typedef METAFILEPICT
// #define NOMINMAX          // Macros min(a,b) and max(a,b)
#define NOMSG             // typedef MSG and associated routines
#define NOOPENFILE        // OpenFile(), OemToAnsi, AnsiToOem, and OF_*
#define NOSCROLL          // SB_* and scrolling routines
#define NOSERVICE          // All Service Controller routines, SERVICE_ equates, etc.
#define NOSOUND              // Sound driver routines
#define NOTEXTMETRIC      // typedef TEXTMETRIC and associated routines
#define NOWH              // SetWindowsHook and WH_*
#define NOWINOFFSETS      // GWL_*, GCL_*, associated routines
#define NOCOMM              // COMM driver routines
#define NOKANJI              // Kanji support stuff.
#define NOHELP              // Help engine interface.
#define NOPROFILER          // Profiler interface.
#define NODEFERWINDOWPOS  // DeferWindowPos routines
#define NOMCX             // Modem Configuration Extensions
#define MMNOSOUND

//----------------------------------------------------------------------------------
// Platform type definitions
// From: https://github.com/DFHack/clsocket/blob/master/src/Host.h
//----------------------------------------------------------------------------------

// #ifdef WIN32
// typedef int socklen_t;
// #endif
// #ifndef RESULT_SUCCESS
// #    define RESULT_SUCCESS 0
// #endif // RESULT_SUCCESS

// #ifndef RESULT_FAILURE
// #    define RESULT_FAILURE 1
// #endif // RESULT_FAILURE

// #ifndef htonll
// #    ifdef _BIG_ENDIAN
// #        define htonll(x) (x)
// #        define ntohll(x) (x)
// #    else
// #        define htonll(x) ((((uint64) htonl(x)) << 32) + htonl(x >> 32))
// #        define ntohll(x) ((((uint64) ntohl(x)) << 32) + ntohl(x >> 32))
// #    endif // _BIG_ENDIAN
// #endif     // htonll

//----------------------------------------------------------------------------------
// Platform specific network includes
// From: https://github.com/SDL-mirror/SDL_net/blob/master/SDLnetsys.h
//----------------------------------------------------------------------------------

// Include system network headers
#if defined(_WIN32)
    #define __USE_W32_SOCKETS
    #define WIN32_LEAN_AND_MEAN
    #include <winsock2.h>
    #include <ws2tcpip.h>
    #include <string>
    #include <io.h>
    // #define IPTOS_LOWDELAY 0x10
#else   // Unix
    #include <sys/types.h>
    #include <fcntl.h>
    #include <netinet/in.h>
    #include <sys/ioctl.h>
    #include <sys/time.h>
    #include <unistd.h>
    #include <net/if.h>
    #include <netdb.h>
    #include <netinet/tcp.h>
    #include <sys/socket.h>
    #include <arpa/inet.h>
#endif

namespace socket_communication {
class Client {
 public:
  Client();
  Client(const std::string ip, const int port);
  ~Client();

  void Init(const std::string ip = "127.0.0.1", const int port = 5001);

  void Send(std::string message);

  std::string Receive();

 private:
  SOCKET client_;
  const int size_message_length_ = 120;  // Buffer size for the length
};
}  // namespace socket_communication

#endif // CLIENT_HPP 