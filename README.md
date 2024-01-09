To-do list: Delete unnecessary files; finish the readme; put the video in public


# Deep-Learning-Volatility


The academic paper realased by Blanka Horvath; Aitor Muguruza and Mehdi Tomas suggests to use deep learning as a speed up for pricing.

By learning the model from model parameters to expected payoff, we can relocate the time-consuming part of calibration, which is the functional evaluation
of prices, to an offline pre-processing of the data. For the on-line calibration part, we are only calibrating a deterministic function, which is fast. 

Neural networks efficiently approximate complex pricing functions offline, addressing calibration challenges in models with slow pricing. 
Such as Rough Volatility models like the rBergomi model.

![image](https://github.com/ideAxel/Deep-Learning-Volatility/assets/118754761/378c5f42-436a-4193-8430-5755b0a2df30)


In this repo we implement the paper with a c++ library to speed up the online pricing and we put the off-line learning phase in a time-laps 
in order to visualise it.
We present a graph with the calibration duration. 



https://github.com/ideAxel/Deep-Learning-Volatility/assets/118754761/a15de6ae-5365-4e7f-9d6c-f64074f1efc2

# In this repo you will find : 
****
The main file:
* File: main.ipynb
* Execute the entire program using this Python script

The C++ File:
* File: cppNeuralNet.cpp
* Includes the hardcoded Neural Net and its gradient

Compilation Output:
* Output File: cppNeuralNet.cp311-win_amd64.pyd
* Facilitates easy code utilization without the need for C++ code compilation.

Configuration File:
* File: setup.py
* Used for C++ compilation if required.


# The youtube video :
ajouter le lien de la vidéo 


https://github.com/ideAxel/Deep-Learning-Volatility/assets/118754761/4e0719d4-3223-4d92-ae97-9e755f795aea


# Config :

Python 3.11.6
Eigen 3.4.O
g++.exe (Rev2, Built by MSYS2 project) 13.2.0

Compilation if needed : python setup.py build_ext --inplace don't forget to relocate :'C:/Users/AD/Desktop/testcpp/eigen/eigen-3.4.0' inside the setup.py

# The orginal paper  : 

[Link to Initial Paper](https://papers.ssrn.com/sol3/papers.cfm?abstract_id=3322085)



# Licence :



# Contact : 
