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

-The main file : main.ipynb 
-The c++ file with the hardcoding of the Neural Net and the gradient : cppNeuralNet.cpp          
-The compilation output to use the code easily : cppNeuralNet.cp311-win_amd64.pyd         
-The config file for the c++ compilation if needed   : setup.py          

# The youtube video :
ajouter le lien de la vidéo 


https://github.com/ideAxel/Deep-Learning-Volatility/assets/118754761/4e0719d4-3223-4d92-ae97-9e755f795aea


# Config : 


# The orginal paper  : 

[Link to Initial Paper](https://papers.ssrn.com/sol3/papers.cfm?abstract_id=3322085)



# Licence :



# Contact : 
