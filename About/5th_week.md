# 5주차 일지

## 목표

1. BehaviorComponent, BehaviorTree, BlackBoard, AIController 완성
    - BehaviorComponent: BlackBoard에 있는 BehaviorKey에 BehaviorType을 전달해주는 컴포넌트
    - BehaviorTree: BlackBoard에 있는 BehaviorKey를 바탕으로 Selector를 통해 정해진 동작 수행
    - BlackBoard: BehaviorKey(취해야할 행동), TargetKey(공격대상), LocationKey(이동위치)를 가지고 있음
    - AIController: AIPerceptionComponent를 통해 Target을 인지하고 거리를 계산해 BehaviorComponent에 명령하는 역할
  
### 특이사항

- 금주 목표는 AI 기능이 도저히 빠른 시일 내에 끝내지 못할 것이라 판단
- 오로지 AI 만큼만은 금주에 끝내야 겠다 판단

## 결과

![스크린샷 2024-08-19 024435](https://github.com/user-attachments/assets/57e66f39-e550-48e2-919e-6a1cec55ec01)

1. BT_Mob, BB_Mob 완성: CBehaviorComponent로 전달받은 BehaviorType을 바탕으로 테스크들을 수행하는 구조

2. CAIController 완성: 공객대상을 인지하고 거리를 계산하여 CBehaviorComponent에 명령하거나 때로는 직접 BlackBoard에 작성

3. CBehaviorComponent 완성: BlackBoard에 BehaviorType을 작성

## 평가

1. BehaviorType을 Blackboard에 전달해주기 위해 서비스를 사용할까, 컨트롤러에서 진행할까
     - 서비스를 사용하면 컨트롤러가 가벼워지지만 이동 중간에 공격 범위 안에 들어와도 바로 공격하지 못함
     - 컨트롤러에서 진행하면 컨트롤러가 무거워지지만 이동 중간에 공격 범위 안에 들어오면 바로 공격함

2. CBehaviorComponent의 기능 범위
     - 오로지 BehaviorType 전달 기능만 갖고 있기엔 살짝 아쉬움
     - TargetKey와 LocationKey를 굳이 가지고 있을 필요가 있을지 의문

3. BT_Boss, BB_Boss는 BT_Mob, BB_Mob을 기반으로 만들되, 좀 더 추가될 요소가 있을 예정

4. CollisionComponent를 서둘러 완료하여 충돌 시스템을 완성해야 진정으로 테스트를 진행할 수 있을 듯함
