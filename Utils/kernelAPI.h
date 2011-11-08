#ifndef _kernelAPI_H_
#define _kernelAPI_H_

#include "tnvme.h"
#include "dnvme.h"


/**
* This class is meant not be instantiated because it should only ever contain
* static members. These utility functions can be viewed as wrappers to
* perform common, repetitous tasks which avoids coping the same chunks of
* code throughout the framework.
*
* @note This class may throw exceptions, please see comment within specific
*       methods.
*/
class KernelAPI
{
public:
    KernelAPI();
    virtual ~KernelAPI();

    /**
     * Disables the NVME device completely, disables IRQ's, and clears out
     * group level resources upon each call.
     * @note This method will not throw
     * @return true upon success, otherwise false
     */
    static bool SoftReset();

    typedef enum {
        MMR_CQ,             // Desire to map SQ memory
        MMR_SQ,             // Desire to map CQ memory
        MMR_META,           // Desire to map meta data memory
        MMAPREGION_FENCE    // always must be last element
     } MmapRegion;

    /**
     * For all mmap operations this method understand the unique encoding
     * which is needed to specify what memory to map into user space.
     * @note This method may throw
     * @param fd Pass the file descriptor to the NVME device to commune
     * @param bufLength Pass the # of bytes consisting of the buffers total size
     * @param bufID Pass the buffer's ID corresponding to param region
     * @param region Pass what region of memory is being requested for mapping
     * @return A user space pointer to the mapped kernel memory, NULL indicates
     *      a failed mapping attempt.
     */
    static uint8_t *mmap(int fd, size_t bufLength, uint16_t bufID,
        MmapRegion region);
    static void munmap(uint8_t *memPtr, size_t bufLength);

    /**
     * Dump the entire dnvme metrics structure for the specified device. The
     * filename will be opened and cleared of any contents before writing.
     * @note This method may throw
     * @param fd Pass the device FD, not the filename, to extract dump data from
     * @param filename Pass the filename in the current directory to write into
     */
    static void DumpKernelMetrics(int fd, string filename);
};


#endif
