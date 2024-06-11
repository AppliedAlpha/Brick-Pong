# (2024-01) 오픈소스SW개론 : Brick Pong
![Brick Pong Game Screen](https://github.com/AppliedAlpha/Brick-Pong/assets/36326864/c6397936-ecb4-4074-bf6c-7f570ef06ab9)

**Brick Pong**은 [Atari PONG (1972)](https://www.youtube.com/watch?v=fiShX2pTz9A) 게임에, 벽돌깨기를 결합하여 2인이 즐길 수 있도록 만든 게임입니다.

Visual Studio 컴파일러를 사용하여 C++ 언어로 개발하였으며, [SFML (Simple and Fast Multimedia Library)](https://github.com/SFML/SFML)을 활용하여 게임을 제작하였습니다.

## How To Play
![Brick Pong How To Play](https://github.com/AppliedAlpha/Brick-Pong/assets/36326864/76b6ebd5-b92c-41a1-a409-82eb02bebb0a)

- 1P는 W와 S, 2P는 ↑와 ↓ 키를 이용하여 `보드(Board)`를 위아래로 움직일 수 있습니다.

- `공(Ball)`은 보드(Board)에 맞으면 반대 방향으로 튕겨져 나가며, 벽돌(Brick)에 맞으면 닿은 벽돌을 부숩니다.

- 공은 벽돌에 맞으면 날아가는 속도가 빨라집니다.

- 공이 상대편 방향 스크린 끝에 닿으면 승점 1점을 얻으며, 게임 화면 뒷 편에 자신의 승점이 표기됩니다.

- 먼저 5점을 얻으면 승리합니다.

## How To Download
현재 지원하는 플랫폼은 `Windows 10 이상`의 환경입니다.

<br />

- Release를 통한 다운로드

    - [<u>Latest Release Link</u>](https://github.com/AppliedAlpha/Brick-Pong/releases/tag/1.1) (v1.1)

1. 상단 링크를 통해 Release로 이동합니다.
1. Release 하단에 첨부된 `Brick_Pong_v1.1.zip` 파일을 다운로드 받습니다.
1. 다운로드받은 파일의 압축을 푼 후에, 해당 폴더에 들어가 `Brick Pong.exe` 파일을 실행합니다.

<br />

- GitHub 저장소 Clone을 통한 다운로드

1. 현재 저장소(https://github.com/AppliedAlpha/Brick-Pong) 를 Clone합니다.
1. 디렉토리 최상단에 있는 builds 폴더에 들어가, `Brick Pong.exe`를 실행합니다.

    - Windows CMD에서 실행 시
    ```cmd
    git clone https://github.com/AppliedAlpha/Brick-Pong

    cd .\Brick-Pong
    ".\builds\Brick Pong.exe"
    ```

## How To Contribute & Feedback

[![Feature Requests](https://img.shields.io/github/issues/AppliedAlpha/Brick-Pong/feature-request.svg)](https://github.com/AppliedAlpha/Brick-Pong/issues?q=is%3Aopen+is%3Aissue+label%3Afeature-request+sort%3Areactions-%2B1-desc)
[![Bugs](https://img.shields.io/github/issues/AppliedAlpha/Brick-Pong/bug.svg)](https://github.com/AppliedAlpha/Brick-Pong/issues?utf8=✓&q=is%3Aissue+is%3Aopen+label%3Abug)

버그나 수정 요청 사항이 있다면, [Repository Issue Page](https://github.com/AppliedAlpha/Brick-Pong/issues)에 제보해주시기 바랍니다!

상단 라벨을 클릭해서 요청할 수도 있습니다. 

## Contributor & Collaborators
### Jihun Kim (PM)
- [**@AppliedAlpha**](https://github.com/AppliedAlpha)   
- <appliedalpha@naver.com> / <jihoon70762@gmail.com>

### O Jae O
- [**@OruteZ**](https://github.com/OruteZ)
- <dwd0102@sju.ac.kr>

### Hyeongjun Kim
- [**@Kimhyeog**](https://github.com/Kimhyeog)

### Changin Lim
- [**@cba700**](https://github.com/cba700)

## License
#### Developed For Term Project of `Introduction to Open Source Software(OSS)` 
- 2024 Spring, Class 002, Team 3

<br />

Copyright (c) 2024 OSS Team 3 "Brick Pong" All rights reserved.

이 프로그램은 [MIT 라이선스](LICENSE.txt)에 기반을 두고 있습니다.

## External Libraries & Special Thanks
- [SFML (Simple and Fast Multimedia Library)](https://github.com/SFML/SFML)
    - C++ Windowing, Graphic 등을 지원하는 멀티미디어 API
    - [zlib/libpng license](https://github.com/SFML/SFML/blob/master/license.md) 라이선스 기반 (제한 없이 사용 가능)

- [Shields.io (Legible Badges)](https://img.shields.io/)
    - README.md 이슈/요청사항 제보 라벨에 사용