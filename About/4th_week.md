# 4주차 일지

## 목표

1. ACMob 클래스 완성
    - AI 관련 요소들은 ACEnemy에서 분리시키기로 결정
    - Behavior Tree, BlackBoard, AIController
  
2. ACProjectile 클래스 작성
    - 투사체에 대한 클래스 생성 필요
  
3. CollisionComponent 작성
    - 충돌체의 충돌에 대한 이벤트를 처리할 컴포넌트 필요
    - 캐릭터 뿐만 아니라 투사체에도 해당 컴포넌트가 부착될 예정
  
### 특이사항

- 금주 목표는 3주차 목표와 동일

## 경과

1. ACMob 클래스 완성 -> ACEnemy 클래스 내 AI 관련 요소 완성
     - AI 관련 요소들을 ACMob 클래스로 분리시키려 했으나
     - ACEnemy에 AI 관련 요소들을 만들기로 결정
     - ACEnemy를 상속받은 모든 몬스터, 보스몹에 적용시키기 편리하게 함

![Gideon Projectile](https://github.com/user-attachments/assets/cf756f3d-065f-4425-bd2e-7578980c0dc8)

2. ACProjectile 클래스 작성
     - Gideon이 사용하는 투사체는 ACProjectile 클래스를 상속받아 블루프린트로 작업
     - 앞으로 더 많은 투사체를 추가할 것

3. CollisionComponent 작성
     - 컴포넌트 생성
     - 필요한 멤버 변수, 멤버 함수 구상 미완
  
## 평가

1. 진짜로 AI를 부여하려면 본격적으로 BT에 사용할 Task, EQS 등을 만들어야함
   
2. 투사체 스폰 관련 이슈 해결해야함
      - 파티클 내 메시는 투사체 액터 스폰 시 따로 스폰 위치를 전달해줘야함
      - 이슈 참고
        
3. 충돌 시 충돌체를 구분해줄 뭔가가 필요함
      - 상대 액터에게 데미지를 줄 무기 충돌체, 투사체 충돌체를 다른 충돌체와 구분해줘야함
      - 지금 당장 떠오르는 방법은 태그...?
