![header](https://capsule-render.vercel.app/api?type=waving&color=gradient&height=280&section=header&text=D3D11%20Pal%20World&fontSize=70&fontColor=ffffff&fontAlign=50&fontAlignY=45)

# 🎮 D3D11를 활용한 팰 월드 모작 포트폴리오

## ⭐ 하이라이트
|▼ 제트래곤 탈것|▼ 작업 시스템|
|:---|:---|
|<img src="https://github.com/user-attachments/assets/8eb0b914-413b-42c4-aca4-964df61daebb" width="368" height="207">|<img src="https://github.com/user-attachments/assets/88e09dce-bc56-4a4a-86c3-c54df61267ed" width="368" height="207">|
|**▼ 팰 포획과 사용자 인터페이스**|**▼ 일렉판다 보스와 스킬 이펙트들**|
|<img src="https://github.com/user-attachments/assets/4b341954-e505-4504-b7a4-1a2bd81093a7" width="368" height="207">|<img src="https://github.com/user-attachments/assets/5c441254-aa4c-4de8-b9c5-12a36a0e55e3" width="368" height="207">|
<br>

## 🔗 링크
- [팰 월드 포트폴리오 동영상](https://youtu.be/4P-o30v-OVo)
- 팰 월드 기술 소개서는 첨부 파일에 있습니다.
<br>

## 🔎 프로필
- 이름 `D3D11를 활용한 팰 월드 모작`
- 기간 `2024-03 ~ 2024-05`
- 인원 `5명(팀장)`
- 역할 `엔진, 클라이언트`
- 장르 `3D`, `오픈월드`
- 플랫폼 `PC`
<br>

## ⚙️ 개발 환경
- 언어 `C++`, `D3D11`
- 통합개발환경 `Visual Studio 2022`, `Blender`
- 형상관리 `Git`
- 운영체제 `Windows 11`
<br>

## 💻 목적
- 렌더링 파이프라인을 학습하고 `DX11 라이브러리`로 프레임워크를 제작합니다.
- 전투 외에 작업, 건축, 제작, 탈것 등 `다양한 콘텐츠`를 구현합니다.
- 2개월 동안 `팀장`으로서 팀을 올바르게 이끄는 방법을 배웁니다.
<br>

## 📜 ️구현 사항
- `비헤이비어 트리`를 구성하는 컴포지트, 데코레이터, 태스크 노드를 개발하고 세 가지 행동 패턴을 설계해 `몬스터 8종`, `보스 2종`을 구현합니다.
- `피직스 라이브러리`를 분석해 리지드 액터, 하이트필드, 트라이앵글 메시를 포함하는 콜라이더 컴포넌트를 제작하고 트리거 충돌과 콜라이더 충돌을 구현합니다.
- 3차원 공간을 분할하고 플레이어 주변에 있는 객체만 업데이트해 `CPU 연산량`을 `최적화`합니다.
- 서브 스레드에서 작업을 실행시킬 수 있는 `스레드 매니저`를 개발하고 람다식을 전달해 비동기로 리소스를 불러옵니다.
- 몬스터에게 일을 분배하는 `작업 시스템`과 플레이어, 몬스터, 보스 간의 `전투 시스템`을 구현합니다.
<br>

## ⓒ 2024 Tak Junseok all rights reserved.
이 리포지토리에 기재된 코드와 리포트에 대한 저작권은 탁준석에게 있습니다. 사전에 합의되지 않은 내용을 무단으로 도용(URL 연결 등), 불법으로 복사(캡처)하여 사용할 경우 사전 경고 없이 저작권법에 의한 처벌을 받을 수 있습니다.

The copyright for the codes and reports listed in this repository belongs to Tak Junseok. If you steal(such as URL connection) or illegally copy(capture) anything that is not agreed in advance, you may be punished by copyright law without prior warning.
