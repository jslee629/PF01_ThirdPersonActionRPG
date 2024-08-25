# 6주차 일지

## 목표

1. 데미지 시스템 완성
    - CollisionComponent: 캐릭터의 모든 충돌을 관리하는 컴포넌트
    - Damaged 함수: TakeDamage를 대신할 ICCharacterInterface에 추가될 가상함수
    - AttributeComponent: 데미지를 체력에 반영하고, 죽음에 대해 알려줄 기능 추가해야함

## 경과

1. CollisionComponent: 캐릭터로부터 충돌 이벤트 안의 파라미터를 받아와 데미지를 계산하고 다시 캐릭터의 Damaged 함수를 호출하는 시스템 구현
2. Damaged 함수: 아직 플레이어가 맞았을때 플레시 머티리얼을 보여주는 코드 작성 못함
3. AttributeComponent에서 죽음에 대해 알려줄 기능 아직 구현 못함

## 평가

1. 그 동안 몰랐던 새로운 문제가 생김
     - 컴포넌트들의 초기화 작업이 캐릭터에서 잘 진행된다고 생각했는데 아니었음
     - PostInitializeComponents에서도 진행이 되지 않음
     - 각 컴포넌트에서 따로 진행할려고 해도 어떤 라이프 사이클에서도 잘 진행되지 않음
     - [이슈 참고](https://github.com/jslee629/PF01_ThirdPersonActionRPG/issues/2)
