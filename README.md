<div align="center">
<p>
 <img width="100px" src="https://raw.githubusercontent.com/NekoSilverFox/NekoSilverfox/403ab045b7d9adeaaf8186c451af7243f5d8f46d/icons/silverfox.svg" align="center" alt="NekoSilverfox" />
 <p align="center"><b><font size=6>RTMP、WebRTC、ffmpeg</font></b></p>
 <p align="center"><b></b></p>
</p>


[![License](https://img.shields.io/badge/license-Apache%202.0-brightgreen)](LICENSE)

<div align="left">
<!-- 顶部至此截止 -->
[toc]

# 前置知识

> 学习路线参考：
>
> https://www.0voice.com/uiwebsite/html/courses/av.html
>
> 
>
> 视频教程：
>
> https://ke.qq.com/course/3202131#term_id=103329919
>
> 
>
> 文字教程
>
> https://ffmpeg.xianwaizhiyin.net/
>
> 
>
> 安装 ffmpeg4.2
>
> https://juejin.cn/post/7074487874451668999
>
> 安装后测试：
>
> ```
> ffplay rtmp://ns8.indexforce.com/home/mystream
> ```



 **RTMP（Real Time Messaging Protocol）：**

- **定义**：RTMP是“实时消息传输协议”的缩写，最初由Macromedia开发，后来被Adobe收购。它主要用于在Flash**播放器和服务器之间传输音频、视频和其他数据**。
- **特点：**
    - **低延迟**：RTMP非常适合实时应用，如直播，因为它能够快速传输数据。
    - **广泛支持**：许多流媒体服务器和播放器都支持RTMP。
    - **适应性**：它支持不同的数据传输速率，适应用户的网络条件。

---

**WebRTC（Web Real-Time Communication）：**

- **定义**：WebRTC是一个开源项目，旨在通过简单的API在网页浏览器中实现**实时通讯**功能，包括视频聊天、语音通话和P2P文件分享等。
- **特点：**
    - **无插件**：在支持WebRTC的浏览器中，用户无需安装任何插件即可进行实时通信。

- **高度互动**：提供低延迟的音视频通信，非常适合视频会议、在线教育和实时游戏等应用。
- **端到端加密**：通信过程中的数据安全性得到了保障。
- **广泛兼容**：得益于其开源特性，WebRTC得到了多个主流浏览器的支持，包括Chrome、Firefox、Safari等。

---

**FFmpeg：**

- **定义**：FFmpeg是一个开源的音视频处理工具集，用于录制、转换和流化音视频。它包括了众多的音视频编解码器、滤镜和格式转换器。
- **特点：**
    - **功能强大**：支持几乎所有的音视频格式，可以进行编码、解码、转码、混流、滤镜处理等。
    - **高效率**：优化的算法确保了处理速度快，资源占用少。
    - **灵活性**：适用于各种不同复杂度的音视频处理任务，从简单的格式转换到复杂的视频编辑。
    - **广泛应用**：在视频编辑、直播、视频会议等多个领域有着广泛的应用。









