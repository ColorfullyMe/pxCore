// pxCore CopyRight 2007-2015 John Robinson
// pxUtil.h
#ifndef PX_UTIL_H
#define PX_UTIL_H
#include "rtFile.h"

#include <vector>

class pxTimedOffscreenSequence
{
public:
  pxTimedOffscreenSequence():mNumPlays(0) {}
  ~pxTimedOffscreenSequence() {}

  void init();
  void addBuffer(pxBuffer &b, double duration);

  uint32_t numFrames()
  {
    return mSequence.size();
  }

  uint32_t numPlays()
  {
    return mNumPlays;
  }

  void setNumPlays(uint32_t numPlays)
  {
    mNumPlays = numPlays;
  }

  pxOffscreen &getFrameBuffer(int frameNum)
  {
    return mSequence[frameNum].mOffscreen;
  }

  double getDuration(int frameNum)
  {
    return mSequence[frameNum].mDuration;
  }

  double totalTime()
  {
    return mTotalTime;
  }

private:
  struct entry
  {
    pxOffscreen mOffscreen;
    double mDuration;
  };

  std::vector<entry> mSequence;
  double mTotalTime;
  uint32_t mNumPlays;
};

rtError pxLoadImage(const char* imageData, size_t imageDataSize, 
                    pxOffscreen& o);
rtError pxLoadImage(const char* filename, pxOffscreen& b);
rtError pxStoreImage(const char* filename, pxOffscreen& b);

//bool pxIsPNGImage(const char* imageData, size_t imageDataSize);

rtError pxLoadAImage(const char* imageData, size_t imageDataSize,
  pxTimedOffscreenSequence &s);
rtError pxLoadAPNGImage(const char *imageData, size_t imageDataSize,
  pxTimedOffscreenSequence &s);

rtError pxLoadPNGImage(const char* imageData, size_t imageDataSize, 
                       pxOffscreen& o);
rtError pxLoadPNGImage(const char* filename, pxOffscreen& o);
rtError pxStorePNGImage(const char* filename, pxOffscreen& b,
                        bool grayscale = false, bool alpha=true);

rtError pxStorePNGImage(pxOffscreen& b, rtData& pngData);

#if 0
bool pxIsJPGImage(const char* imageData, size_t imageDataSize);
rtError pxStoreJPGImage(const char* filename, pxBuffer& b);
#endif
#ifdef ENABLE_LIBJPEG_TURBO
rtError pxLoadJPGImageTurbo(const char* buf, size_t buflen, pxOffscreen& o);
#endif //ENABLE_LIBJPEG_TURBO
rtError pxLoadJPGImage(const char* imageData, size_t imageDataSize, 
                       pxOffscreen& o);
rtError pxLoadJPGImage(const char* filename, pxOffscreen& o);

#endif