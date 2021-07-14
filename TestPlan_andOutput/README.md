#  Test Plan

|Test_ID|Description|Expected_input|Expected_output|
|-------|-----------|--------------|---------------|
|H_01|check if the name variable is given only strings or not|string without spaces|the name variable should be assigned with the given string|
|H_02|check if the mobile number given contains only 10 digits|10 digit integer|the 10 digit number should be assigned to mobile variable|
|H_03|Check the amount the customer wants to pay is less than or equal to the E-wallet balance|1.Floating point value, 2. integer|deduct the payed amount from e-wallet and update the balance|
