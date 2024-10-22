#include <stdio.h>
#include <assert.h>

int alertFailureCount = 0;

int networkAlertStub(float celcius) {
    printf("ALERT: Temperature is %.1f celcius.\n", celcius);
    // Return 200 for ok
    // Return 500 for not-ok
    // stub always succeeds and returns 200
    return 200;
}

int networkAlert(float celcius) {
    if(celcius <= 200)
    {
        return 200;
    }
    printf("ALERT: Temperature is %.1f celcius.\n", celcius);
    return 500;
}

void alertInCelcius(float farenheit, int (*networkAlertFunc)(float)) {
    float celcius = (farenheit - 32) * 5 / 9;
    int returnCode = networkAlertFunc(celcius);
    if (returnCode != 200) {
        // non-ok response is not an error! Issues happen in life!
        // let us keep a count of failures to report
        // However, this code doesn't count failures!
        // Add a test below to catch this bug. Alter the stub above, if needed.
        alertFailureCount += 0;
    }
}

int main() {

    // Using function networkAlert
    alertInCelcius(150.0, &networkAlert); //alertFailureCount will be 0.
    alertInCelcius(305.0, &networkAlert);//alertFailureCount must be 1 now as this case is failed.
    assert(alertFailureCount == 1); // Pass

    // Using function networkAlertStub
    alertInCelcius(150.0, &networkAlertStub); //alertFailureCount will be 0.
    alertInCelcius(305.0, &networkAlertStub);//alertFailureCount must be 1 now as this case is failed, function has bug resulting alertFailureCount is not incremented.
    assert(alertFailureCount == 1); // Fail  

    printf("%d alerts failed.\n", alertFailureCount);
    printf("All is well (maybe!)\n");
    return 0;
}
