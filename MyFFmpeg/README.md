# MyFFmpeg

Some FFmpeg commands and solutions.

## FFmpeg commands

| Command | Description |
| :--- | :--- |
| ffmpeg -i \<input_file\> -f srt -i \<srt_file\> -c:v copy -c:a copy -c:s mov_text \<output_file\> | Embed SRT file into mp4 with ffmpeg |
| ffmpeg -ss \<begin_time\> -to \<end_time\> -i \<input_file\> -c:v copy -c:a copy \<output_file\> | Cut the video or audio from specified begin time to end time |
| ffmpeg -i INPUT1 -i INPUT2 -i INPUT3 -filter_complex amix=inputs=3:duration=first OUTPUT | mix 3 input audio streams to a single output with the same duration as the first input |