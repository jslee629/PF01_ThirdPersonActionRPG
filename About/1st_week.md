# 1주차 일지

## 목표

1. 모든 캐릭터에 공통적으로 붙게 될 ActionComponent, StateComponent, AttributeComponent 완성
    - ActionComponent: 캐릭터의 모든 액션을 실행시키는 컴포넌트 (몽타주 재생)
    - StateComponent: 캐릭터의 상태를 관리하는 컴포넌트. 상태는 액션 실행의 조건
    - AttributeComponent: 캐릭터의 체력, 공격력, 방어력 등 RPG에 필수적인 요소들을 관리하는 컴포넌트

2. 위의 컴포넌트들을 모두 붙인, 모든 캐릭터의 공통 부모 클래스가 될 ACPlayer 클래스 완성
    - 완성이지만 후에 추가적으로 컴포넌트를 더 만들어 부착시킬 수도 있음

3. ACPlayer 클래스를 상속받은 다른 캐릭터 클래스 블루프린트 생성
    - 이미 완성시킨 모든 애니메이션 블루프린트의 부모 클래스가 될 UCAnimInstance를 상속받은 애니메이션 블루프린트도 생성
    - 해당 애니메이션 블루프린트가 사용할 애니메이션들도 리타깃팅 수행
    - 기본적인 몽타주들도 리타깃팅 수행

## 경과

![컴포넌트](https://github.com/user-attachments/assets/e894636c-005a-4605-88fd-1aed5e5ee605)
![뷰포트](https://github.com/user-attachments/assets/971b0a06-ff74-4101-b41a-5ef79d1b0fa5)

1. 목표했던 세 가지 컴포넌트 모두 완성하여 캐릭터에 부착됨
2. ACPlyaer를 완성하여 캐릭터에 상속됨
3. 기본적인 몽타주 리타깃은 맞는 리액션과 구르기 액션밖에 없긴 하지만 수행 완료

## 평가

1. 아직 애니메이션 블루프린트를 완성시키진 못함
2. 새로운 캐릭터에 사용될 애니메이션과 애님몽타주를 아직 완성하지 못함
