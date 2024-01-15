def solution(bridge_length, weight, truck_weights):
    truck_weights_edit = []
    for truck_weight, ind in zip(truck_weights, [0] * len(truck_weights)):
        truck_weights_edit.append([ind, truck_weight])
    bridge_in = []
    trucks = []
    answer = 0
    while truck_weights_edit or bridge_in:
        if truck_weights_edit and (sum(bridge_in) + truck_weights_edit[0][1]) <= weight:
            truck = truck_weights_edit.pop(0)
            trucks.append(truck)
            bridge_in.append(truck[1])

        for t in trucks:
            t[0] = t[0] + 1
            if t[0] == bridge_length:
                bridge_in.pop(0)
                trucks.pop(0)
        answer += 1
    return answer

if __name__ == "__main__":
    # print(solution(2, 10, [7,4,5,6]))
    # print(solution(100, 100, [10,10,10,10,10,10,10,10,10,10]))
    # print(solution(100, 100, [10]))
    print(solution(10, 100, [50, 30, 10, 10, 30, 10, 40]))