#include <pybind11/stl.h>
#include <vector>
#include <cmath>
#include <Eigen/Dense>
#include <pybind11/eigen.h>
#include <utility>

namespace py = pybind11;
using Eigen::MatrixXd;
using Eigen::VectorXd;

class NeuralNetworkFunctions {
public:
    static const int NumLayers = 4;
    static const int NumParameters = 11;

    // Activation Function: ELU
    MatrixXd Elu(const MatrixXd& x) {
        MatrixXd y = x;
        for (int i = 0; i < y.rows(); ++i) {
            for (int j = 0; j < y.cols(); ++j) {
                y(i, j) = y(i, j) < 0 ? std::exp(y(i, j)) - 1 : y(i, j);
            }
        }
        return y;
    }

    // Derivative of the ELU function
    MatrixXd EluPrime(const MatrixXd& x) {
        MatrixXd y = x;
        for (int i = 0; i < y.rows(); ++i) {
            for (int j = 0; j < y.cols(); ++j) {
                y(i, j) = y(i, j) < 0 ? std::exp(y(i, j)) : 1;
            }
        }
        return y;
    }

    // Neural Network Forward Pass
    VectorXd NeuralNetwork(const VectorXd& x, const std::vector<std::pair<MatrixXd, VectorXd>>& NNParameters) {
        VectorXd input1 = x;
        for (int i = 0; i < NumLayers; ++i) {
            const auto& layer = NNParameters[i];
            input1 = layer.first.transpose() * input1 + layer.second;
            input1 = Elu(input1); // Apply ELU activation function
        }
        // Process the final layer
        const auto& finalLayer = NNParameters.back();
        MatrixXd Matrice = finalLayer.first.transpose() * input1 + finalLayer.second;

        VectorXd result = Eigen::Map<VectorXd>(Matrice.data(), Matrice.size());

        return result;
    }
    




    //Neural Network gradient Computation
    MatrixXd NeuralNetworkGradient( const VectorXd& x, const std::vector<std::pair<MatrixXd, VectorXd>>& NNParameters){
        MatrixXd grad = MatrixXd::Identity(NumParameters, NumParameters);
        VectorXd input1 = x;

        //Grad Spread 
        for(int i = 0; i < NumLayers; ++i){
            const auto& layer = NNParameters[i];
            input1 = layer.first.transpose() * input1 + layer.second;
            grad = grad* layer.first;

            //Chain Rule
            VectorXd eluPrimeResult = EluPrime(input1);
            for (int j = 0 ; j < grad.rows(); ++j){
                for (int k = 0 ; k < grad.cols(); ++k){
                    grad(j,k) *= eluPrimeResult(k);
                }
            }
            input1 = Elu(input1);
        }  

        //Process the final layer
        const auto& nextLayer = NNParameters.back();
        grad = grad * nextLayer.first;

        return grad;         
    }





























};

PYBIND11_MODULE(cppNeuralNet, m) {
    m.doc() = "Object-oriented NeuralNet"; // Module documentation
    py::class_<NeuralNetworkFunctions>(m, "NeuralNetworkFunctions")
        .def(py::init<>())
        .def("Elu", &NeuralNetworkFunctions::Elu, "ELU activation function (Eigen version)")
        .def("EluPrime", &NeuralNetworkFunctions::EluPrime, "Derivative of ELU (Eigen version)")
        .def("NeuralNetwork", &NeuralNetworkFunctions::NeuralNetwork, "Compute network output")
        .def("NeuralNetworkGradient", &NeuralNetworkFunctions::NeuralNetworkGradient, "Gradient of neural network");
}