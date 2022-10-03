---
title: ExistOS Project
---

## ExistOS for HP39gii

[![GPL Licence](https://badges.frapsoft.com/os/gpl/gpl.png?v=103)](https://opensource.org/licenses/GPL-3.0/)
[![Build Status](../../../actions/workflows/build.yml/badge.svg)](../../../actions/workflows/build.yml)

|                             中文                              |                             English                              |
| :-----------------------------------------------------------: | :--------------------------------------------------------------: |
| ExistOS 是一群计算器爱好者们为 HP39gii 所创立的开源固件项目。 | ExistOS is a firmware project created by calculator enthusiasts. |
|      我们欢迎您试用本系统，并为项目提出意见、作出贡献。       |      Welcome to try out and improve this firmware project.       |
|              [安装教程](./zh-cn/installation.md)              |            [Installaion Guide](./en/installation.md)             |
|                 [使用指南](./zh-cn/manual.md)                 |                  [User Manual](./en/manual.md)                   |
|             [卸载 ExistOS](./zh-cn/uninstall.md)              |              [Uninstall ExistOS](./en/uninstall.md)              |
|              [贡献教程](./zh-cn/contribution.md)              |            [Contribution Guide](./en/contribution.md)            |

Thanks to [FreeRTOS kernel](https://github.com/FreeRTOS/FreeRTOS), [TinyUSB](https://github.com/hathach/tinyusb), [FatFs](http://elm-chan.org/fsw/ff/00index_e.html), [dhara](https://github.com/dlbeer/dhara), [KhiCAS](http://www-fourier.ujf-grenoble.fr/~parisse/giac.html) and others great open source project.

### Todo List

- [x] Boot
- [x] 调试串口
- [x] LCD 256 级灰度 屏幕驱动
- [x] STMP3770 中断控制器
- [x] 键盘驱动（GPIO 轮询）
- [x] 定时器驱动
- [x] CPU 频率设定
- [x] RTC 时钟
- [x] USB 大容量存储模式
- [x] USB 串口控制台
- [x] USB 模拟键盘鼠标
- [x] USB 功能动态配置
- [x] FLASH 驱动
- [x] FATFS 文件系统
- [x] 多任务
- [x] 虚拟内存
- [x] APP 加载
- [x] 最小化 MicroPython 实现
- [x] 用户界面 GUI
- [x] 基本电源管理
- [x] 完全脱离官方刷机工具的固件升级

### Experimental features

- [x] USB 输入镍氢电池充电功能
- [x] Saturn 模拟器运行 hp39g 固件
- [ ] Saturn 模拟器运行 hp48g 固件
