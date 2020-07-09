# Kylin Video
## Overview
Kylin Video is a video playing application based on MPlayer and MPV. The main interface is simple and easy-to-use, as shown in Fig 1.

![Fig 1 Kylin Video-big](image/1.png)

The supported formats as shown below.

| Category | Supported Formats |
| :------------ | :------------ |
| Video	|(*.avi *.vfw *.divx *.mpg *.mpeg *.m1v *.m2v *.mpv *.dv *.3gp *.mov *.mp4 *.m4v *.mqv *.dat *.vcd *.ogg *.ogm *.ogv *.ogx *.asf *.wmv *.bin *.iso *.vob *.mkv *.nsv *.ram *.flv *.rm *.swf *.ts *.rmvb *.dvr-ms *.m2t *.m2ts *.mts *.rec *.wtv *.f4v *.hdmov *.webm *.vp8 *.bik *.smk *.m4b *.wtv *.part )
| Audio |(*.mp3 *.ogg *.oga *.wav *.wma *.aac *.ac3 *.dts *.ra *.ape *.flac *.thd *.mka *.m4a *.opus )
| Subtitle |	(*.srt *.sub *.ssa *.ass *.idx *.txt *.smi *.rt *.utf *.aqt *.vtt )

<br>

## Basic Function
Icons and function:

| Icon | Function | Icon | Function |
| :------------ :| :------------ | :------------ | :------------ |
|![](image/icon1.png)| Advanced function |![](image/icon3.png)| Play |
|![](image/icon9.png)| Previous |![](image/icon4.png)| Pause |
|![](image/icon10.png)| Next |![](image/icon5.png)| Volume |
|![](image/icon11.png)|	Full screen |![](image/icon6.png)| Playlist |

### Full Screen
Click the icon ”![](image/icon11.png)” at the bottom right corner or double-click the screen to open full screen mode.

### Playlist
Click the icon “![](image/icon6.png)” at the bottom right corner to view the playlist, add or remove files, as shown in Figure 2.

![Fig 2 Playlist-big](image/2.png)

#### Right-click Menu
Right click a selected file in the playlist, and the options as shown below.

![Fig 3 Right-click menu-big](image/3.png)

#### Add
Click “Add” in the play list to select files, as shown in Figure 4. Multiple choices by pressing Ctrl at the same time.

![Fig 4 Add file-big](image/4.png)

#### Clear
- Way 1: Click "Clear" and select "Yes" to empty the playlist. As shown in Fig 5.

![Fig 5 Empty playlist](image/5.png)

- Way 2: The mouse hovers on a file in the playlist, and then click the appeared icon, as shown in Figure 6.

![Fig 6 Delete a file-big](image/6.png)

- Way 3: Remove from right-click menu.

<br>

## Advanced Function
Click the icon "![](image/icon1.png)" at the top right corner of the main interface, and select "Preferences".

![Fig 7 Preference](image/7.png)

### General
Select playback engine: MPlayer or MPV. And accroding to the needs, customize that whether pause when minimized, preview when video is playing. As shown in Figure 7.

### Video
Set output driver and other options, such as postprocessing, video equalizer, rendering, etc.. As shown in Fig 8. 

![Fig 8 Video](image/8.png)

### Audio
According to users needs, it can customize volume (global volume, volume control, default volume normalization, etc.), synchronization (audio/video synchronization, factor), output driver and channel.

![Fig 9 Audio-big](image/9.png)

### Performance
Customize cache (local files, streams) and decode, as shown in Figure 10.

![Fig 10 Performance](image/10.png)

Hardware decoding formats including None, Auto, vdapu、vaapi、vaapi-copy.

### Subtitles
Set autoload subtitles files (*.srt, *.sub, etc.) -- same name as movie, all subs containing movie name, all subs in directory.

Dedault encoding is UTF-8, and users can check autodetect for this language.

As shown below.

![Fig 11 Subtitles](image/11.png)

### ScreenShot
Customize the saving path and image format, as shown in Fig 12.

![Fig 12 Screenshot](image/12.png)

### Shortcut Key
It allows users to change majority of the current shortcut keys, as shown in Fig 13.

![Fig 13 Shortcut](image/13.png)

Users can double-click or press Enter to modify them, as shown in Fig 14

![Fig 14 Customize shortcut](image/14.png)

- If the capture button is enabled, then you just need to press the new keys for this action. (It doesn’t apply to all buttons)

- If the capture button is disabled, then you can input the full name of the key. 

<br>

## Q&A
### Video can not be played
Try to switch playback engine MPlayer or MPV in general setting.
