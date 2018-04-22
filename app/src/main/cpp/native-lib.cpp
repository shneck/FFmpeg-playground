#include <jni.h>
#include <string>
#include <libavcodec/avcodec.h>
#include <libavformat/avformat.h>

extern "C" JNIEXPORT jstring

JNICALL
Java_com_mmalay_ffmpeg_MainActivity_stringFromJNI(
        JNIEnv *env,
        jobject /* this */) {
    std::string hello = "Hello from C++";
    return env->NewStringUTF(hello.c_str());
}

static void video_decode_example(const char *filename)
{
    // TODO: implement me!
}
