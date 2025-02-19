#include "Reactor.hpp"

/**
 * initialize struct, create listener add to fd to func and poll, return the Reactor
 * @return
 */
Reactor* startReactor() {
    Reactor* r = (Reactor*)malloc(sizeof(Reactor));
    if (!r) {
        perror("malloc");
        exit(1);
    }
    // initialize pfds to 5 spots
    r->fd_count = 0;
    r->fd_size = 5;
    r->run = 1;
    // create
    r->pfds = (struct pollfd*)malloc(sizeof *(r->pfds) * r->fd_size);
    if (!r->pfds) {
        perror("poll");
        free(r);
        exit(1);
    }
    r->f2f = (struct fd_to_func*)malloc(sizeof *(r->f2f) * r->fd_size);
    if (!r->f2f) {
        perror("poll");
        free(r);
        exit(1);
    }
    return r;
}

/**
 * Stops the reactor from running
 * @param r
 * @return
 */
int stopReactor(Reactor* r) {
    if (r) {
        // Free allocated memory
        free(r->pfds);
        free(r->f2f);
        free(r);
    }
    return 0;
}

/**
 * add Fd to reactor
 * @param r - reactor
 * @param fd - file descriptor - client
 * @param func - desired func
 * @return
 */
int addFdToReactor(Reactor* r, int fd, reactorFunc func) {
    // if no room realloc the list
    if (r->fd_count == r->fd_size) {
        r->fd_size *= 2;
        r->pfds = (struct pollfd*)realloc(r->pfds, sizeof(*r->pfds) * r->fd_size);
        r->f2f = (struct fd_to_func*)realloc(r->f2f, sizeof(*r->f2f) * r->fd_size);
    }
    // put fds in next availabe space and update on map
    r->pfds[r->fd_count].fd = fd;
    r->pfds[r->fd_count].events = POLLIN;
    r->f2f[r->fd_count].fd = fd;
    r->f2f[r->fd_count].func = func;
    r->fd_count++;
    return 0;
}

