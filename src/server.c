#include <sys/socket.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
  char *advice[] = {
    "你好，欢迎访问\r\n",
    "请求超时，请重试，哈哈\r\n",
    "卧槽，这是什么情况\r\n",
    "为什么要连接呢\r\n",
    "发现恶意用户!\r\n"
  };

  int listener_d = socket(PF_INET, SOCK_STREAM, 0);
  int reuse = 1;
  if (setsockopt(listener_d, SOL_SOCKET, SO_REUSEADDR, (char *)&reuse, sizeof(int)) == -1) {
    puts("\n无法设置套接字的『重新使用端口』选项");
  }

  struct sockaddr_in name;
  name.sin_family = PF_INET;
  name.sin_port = (in_port_t)htons(30000);
  name.sin_addr.s_addr = htonl(INADDR_ANY);

  if ( bind(listener_d, (struct sockaddr *) &name, sizeof(name)) == -1) {
    puts("\n无法绑定端口");
    exit(1);
  }

  listen(listener_d, 10);
  puts("Waiting for connection");
  while(1) {
    struct sockaddr_storage client_addr;
    unsigned int address_size = sizeof(client_addr);

    int connect_d = accept(listener_d, (struct sockaddr *) &client_addr, &address_size);
    char *msg = advice[rand() % 5];

    send(connect_d, msg, strlen(msg), 0);
    close(connect_d);
  }
  return 0;
}
