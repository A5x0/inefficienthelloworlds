#include <assert.h>
#include <complex.h>
#include <ctype.h>
#include <errno.h>
#include <fenv.h>
#include <float.h>
#include <inttypes.h>
#include <iso646.h>
#include <limits.h>
#include <locale.h>
#include <math.h>
#include <setjmp.h>
#include <signal.h>
#include <stdalign.h>
#include <stdarg.h>
#include <stdatomic.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdnoreturn.h>
#include <string.h>
#include <tgmath.h>
#include <threads.h>
#include <time.h>
#include <uchar.h>
#include <wchar.h>
#include <wctype.h>
#include <aio.h>
#include <dirent.h>
#include <fcntl.h>
#include <fnmatch.h>
#include <ftw.h>
#include <glob.h>
#include <grp.h>
#include <iconv.h>
#include <langinfo.h>
#include <libgen.h>
#include <mqueue.h>
#include <netdb.h>
#include <nl_types.h>
#include <poll.h>
#include <pthread.h>
#include <pwd.h>
#include <regex.h>
#include <sched.h>
#include <semaphore.h>
#include <spawn.h>
#include <syslog.h>
#include <termios.h>
#include <unistd.h>
#include <utime.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <sys/time.h>
#include <sys/times.h>
#include <sys/resource.h>
#include <sys/mman.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <sys/sem.h>
#include <sys/shm.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <sys/uio.h>
#include <sys/ioctl.h>
#include <sys/file.h>
#include <sys/statvfs.h>
#include <sys/select.h>
#include <sys/utsname.h>
#include <sys/sysinfo.h>
#include <sys/epoll.h>
#include <sys/eventfd.h>
#include <sys/signalfd.h>
#include <sys/timerfd.h>
#include <sys/inotify.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <netinet/tcp.h>
#include <netinet/udp.h>
#include <netinet/ip.h>
#include <netinet/ip_icmp.h>
#include <netinet/if_ether.h>
#include <net/if.h>
#include <linux/limits.h>
#include <linux/if_packet.h>
#include <linux/if_arp.h>
#include <linux/if_addr.h>
#include <linux/netlink.h>
#include <linux/rtnetlink.h>
#include <linux/usbdevice_fs.h>
#include <linux/input.h>
#include <linux/fb.h>
#include <linux/kd.h>
#include <linux/vt.h>
#include <linux/soundcard.h>
#include <linux/joystick.h>
#include <linux/rtc.h>
#include <linux/hidraw.h>
#include <linux/serial.h>
#include <linux/icmp.h>
#include <linux/if_tun.h>
#include <execinfo.h>
#include <getopt.h>
#include <malloc.h>
#include <mcheck.h>
#include <obstack.h>
#include <argp.h>
#include <zlib.h>
#include <bzlib.h>
#include <lzma.h>
#include <openssl/ssl.h>
#include <openssl/evp.h>
#include <openssl/rand.h>
#include <openssl/sha.h>
#include <openssl/md5.h>
#include <alsa/asoundlib.h>
#include <pulse/pulseaudio.h>
#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glx.h>
#include <vulkan/vulkan.h>
#include <wayland-client.h>
#include <libudev.h>
#include <libusb-1.0/libusb.h>
#include <drm/drm.h>
#include <drm/drm_mode.h>
#include <curl/curl.h>
#include <systemd/sd-bus.h>
#include <systemd/sd-daemon.h>

uint64_t fib(int n) {
    if (n <= 1) return n;
    return fib(n - 1) + fib(n - 2);
}

char slow_char(int target) {
    for (int i = 0; i < 500; i++) fib(30);
    return (char)target;
}

char *build_string() {
    const int chars[] = {'H','e','l','l','o',',',' ','W','o','r','l','d','!','\n'};
    int len = sizeof(chars)/sizeof(chars[0]);
    char *s = NULL;

    for (int i = 0; i < len; i++) {
        char *new_s = malloc(i + 1);
        for (int j = 0; j < i; j++)
            new_s[j] = s ? s[j] : slow_char('X');
        new_s[i] = slow_char(chars[i]);
        free(s);
        s = new_s;
    }
    return s;
}

void slow_write(const char *s, int len) {
    for (int i = 0; i < len; i++) {
        write(1, &s[i], 1);
        fib(28);
    }
}

int main() {
    char *msg = build_string();
    slow_write(msg, 14);
    free(msg);
}
