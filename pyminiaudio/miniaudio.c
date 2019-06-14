/* #define STB_VORBIS_NO_PUSHDATA_API  */   /*  needed by miniaudio decoding logic  */
#include "miniaudio/stb_vorbis.c"

#define DR_FLAC_IMPLEMENTATION
#define DR_FLAC_NO_OGG
#include "miniaudio/dr_flac.h"

#define DR_MP3_IMPLEMENTATION
#include "miniaudio/dr_mp3.h"

#define DR_WAV_IMPLEMENTATION
#include "miniaudio/dr_wav.h"

#define MINIAUDIO_IMPLEMENTATION
/* #define MA_NO_DECODING */
#define MA_NO_AAUDIO
#define MA_NO_OPENSL
#define MA_NO_WEBAUDIO
#define MA_NO_JACK
#include "miniaudio/miniaudio.h"


void init_miniaudio(void) {

    /* strange, this is needed to avoid a huge multi second delay when using PulseAudio */
    setenv("PULSE_LATENCY_MSEC", "100", 0);

}


void ma_device_config_set_params(ma_device_config* config, ma_uint32 sample_rate, ma_uint32 buffer_size_msec,
  ma_uint32 buffer_size_frames, ma_format format, ma_uint32 channels, ma_format capture_format, ma_uint32 capture_channels) {
    config->sampleRate = sample_rate;
    config->bufferSizeInFrames = buffer_size_frames;
    config->bufferSizeInMilliseconds = buffer_size_msec;
    config->playback.format = format;
    config->playback.channels = channels;
    config->capture.format = capture_format;
    config->capture.channels = capture_channels;
}


/* Nothing more to do here; all the decoder source is in their own single source/include file */
