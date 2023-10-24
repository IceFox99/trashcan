# MyFFmpeg

Some FFmpeg commands and solutions.

## FFmpeg commands

| Command | Description |
| :--- | :--- |
| ffmpeg -ss \<begin_time\> -to \<end_time\> -i \<input_file\> -c:v copy -c:a copy \<output_file\> | Cut the video or audio from specified begin time to end time |
| ffmpeg -i \<INPUT1\> -i \<INPUT2\> -i \<INPUT3\> -filter_complex amix=inputs=3 \<OUTPUT\> | mix 3 input audio streams (any number) to a single output with the shortest duration in the inputs |
| ffmpeg -i \<input_video\> -vn -c:a copy \<output_audio\> | Extract the audio stream without re-encoding |
| ffmpeg -i \<input_video\> -an -c copy \<output_video\> | Remove audio from video |
| ffmpeg -i \<mkv_video\> -i \<ass_sub\> -map 0 -map 1 -c copy \<output_mkv\> | Merge ass subtitles into mkv video |

## Solutions

- [Use ffmpeg to add text subtitles](https://stackoverflow.com/questions/8672809/use-ffmpeg-to-add-text-subtitles)
- [Extract audio from video with ffmpeg](https://stackoverflow.com/questions/9913032/how-can-i-extract-audio-from-video-with-ffmpeg)
- [Add a new audio into a video using ffmpeg](https://stackoverflow.com/questions/11779490/how-to-add-a-new-audio-not-mixing-into-a-video-using-ffmpeg)
- [Loss of quality while adding subtitle via ffmpeg](https://video.stackexchange.com/questions/17548/loss-of-quality-while-adding-subtitle-via-ffmpeg)
