package Hash;

import java.util.HashMap;

import static util.TestUtils.checkResult;

public class 완주하지_못한_선수 {
    public static void main(String[] args) {
        checkResult(solution(new String[]{"leo", "kiki", "eden"}, new String[]{"eden", "kiki"}), "leo");
        checkResult(solution(
                        new String[]{"marina", "josipa", "nikola", "vinko", "filipa"},
                        new String[]{"josipa", "filipa", "marina", "nikola"}),
                "vinko");
        checkResult(solution(
                        new String[]{"mislav", "stanko", "mislav", "ana"},
                        new String[]{"stanko", "ana", "mislav"}),
                "mislav");
    }

    public static String solution(String[] participant, String[] completion) {
        HashMap<String, Integer> nameMap = new HashMap<>();
        for (String name : participant) {
            if (nameMap.containsKey(name)) {
                nameMap.put(name, nameMap.get(name) + 1);
            } else {
                nameMap.put(name, 1);
            }
        }

        for (String name : completion) {
            nameMap.put(name, nameMap.get(name) - 1);
        }

        return nameMap.keySet().stream()
                .filter(key -> nameMap.get(key) == 1)
                .findFirst()
                .orElse("");
    }
}