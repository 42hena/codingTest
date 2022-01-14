# 핸드폰 번호 가리기
def solution(phone_number):
    size = len(phone_number)
    answer = "*" * (size - 4) + phone_number[-4:]
    return answer