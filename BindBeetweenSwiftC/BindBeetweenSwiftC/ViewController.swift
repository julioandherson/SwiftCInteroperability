//
//  ViewController.swift
//  BindBeetweenSwiftC
//
//  Created by Júlio Andherson de Oliveira Silva on 13/09/20.
//  Copyright © 2020 Júlio Andherson de Oliveira Silva. All rights reserved.
//

import Cocoa

class ViewController: NSViewController {

    override func viewDidLoad() {
        super.viewDidLoad()

        registerCppCallback()
        
        // Cpp functions exposed through Bridging-Header.h
        let addResult = add(10, 10)
        let subResult = sub(20, 15)
        let multResult = mult(3, 3)
        let dividerResult = divider(50, 2)
        
        print("Add result: \(addResult)")
        print("Sub result: \(subResult)")
        print("Mult result: \(multResult)")
        print("Div result: \(dividerResult)")

        myCustomCallback()
    }
    
    private func registerCppCallback() {
        NotificationCenter.default.addObserver(self, selector: #selector(myCallbackSelectorFunction), name: NSNotification.Name(rawValue: "MyCallBackTag"), object: nil)
        
        // Setting up callback function throught function's pointer on struct
        var callbacks = StructCallbacks (
            deliveryToSwift: { (msg) in
                NotificationCenter.default.post(name: Notification.Name(rawValue: "MyCallBackTag"), object: msg)
            }
        )
        // Setting up function's pointer
        SetupStructCallback(&callbacks)
    }
    
    @objc func myCallbackSelectorFunction(notf: Notification) {
        let content = notf.object! as! UnsafePointer<CChar>
        print("Callback result: \(String(cString: content))")
    }
}

