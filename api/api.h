#ifndef API_H
#define API_H
#include <unistd.h>
#include <netinet/in.h>
#include <iostream>
#include <string>
#include <map>

void handle_error(char *msg);

std::string cstr2string(const char *str);
std::map<char, std::string> getOption(int argc, char *argv[]);

int Socket(int domain, int type, int protocol);
int Close(int fd);

int Bind(int sockfd, const struct sockaddr *addr, socklen_t addrlen);
int Listen(int sockfd, int backlog);

int Open(const char *pathname, int flags, mode_t mode);
int Stat(const char *pathname, struct stat *buf);
void *Mmap(void *addr, size_t len, int prot, int flags, int fd, off_t offset);
int Munmap(void *start, size_t length) ;

ssize_t writeString(int sockfd, const std::string &str);
ssize_t Rio_writen(int fd, void *usrbuf, size_t n);
ssize_t writeHtml(int sockfd,const std::string &filename);

in_addr_t Inet_addr(const std::string &host);
std::string Inet_ntop(int af, const void *src,
                      char *dst, socklen_t size);

#endif