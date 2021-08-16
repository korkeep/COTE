package util;

import java.util.Objects;

public class TestUtils {
    public static void checkResult(Object actual, Object expect) {
        if (!Objects.equals(actual, expect)) {
            throw new AssertionError(detailMessage(actual, expect));
        }
    }

    private static String detailMessage(Object actual, Object expect) {
        return "Expected is " + expect + ", But actual is " + actual;
    }
}
