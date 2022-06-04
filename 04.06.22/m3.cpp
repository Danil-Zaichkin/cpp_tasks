#include <mutex>

using namespace std;

mutex count;
mutex queue;
mutex resource;

int readersCount = 0;

void reader() {
    queue.lock();
    count.lock();
    readersCount++;
    if (readersCount == 1)
        resource.lock();
    queue.unlock();
    count.unlock();

    //reading...

    count.lock();
    readersCount--;
    if (readersCount == 0)
        resource.unlock();
    count.unlock();
}

void writer() {
    queue.lock();
    resource.lock();
    queue.unlock();

    //writing...

    resource.unlock();
}