#ifndef _THREAD_POOL_H
#define _THREAD_POOL_H

typedef struct thrdpool_s thrdpool_t;
// 任务执行的规范 ctx 上下文
typedef void (*handler_pt)(void * /* ctx */);

#ifdef __cplusplus
extern "C"
{
#endif

// 对称处理
thrdpool_t *thrdpool_create(int thrd_count);

void thrdpool_terminate(thrdpool_t * pool);

int thrdpool_post(thrdpool_t *pool, handler_pt func, void *arg);

void thrdpool_waitdone(thrdpool_t *pool);

#ifdef __cplusplus
}
#endif

#endif