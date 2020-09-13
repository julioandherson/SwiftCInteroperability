//
//  Calculate.hpp
//  BindBeetweenSwiftC
//
//  Created by Júlio Andherson de Oliveira Silva on 13/09/20.
//  Copyright © 2020 Júlio Andherson de Oliveira Silva. All rights reserved.
//

#ifdef __cplusplus
extern "C" {
#endif

    struct StructCallback {                                               // Define a struct
        void (* _Nonnull deliveryToSwift)(const char * _Nonnull msg);     // Define a function's prototype
    };
    typedef struct StructCallback StructCallbacks;                        // Define a struct prototype
    void SetupStructCallback(const StructCallbacks * _Nonnull callback);  // Function to setup function's pointer

    void myCustomCallback();

    int add(int a, int b);
    int sub(int a, int b);
    int mult(int a, int b);
    int divider(int a, int b);

#ifdef __cplusplus
}
#endif
