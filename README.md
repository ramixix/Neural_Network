# Neural_Network

Nerual networks form the base of deep learning, that itself is subset of machine learning, where the algorithms are inspired by the structure of human brain.

pic

Neural networks take in data and train themselves to recognize the patterns in this data and predict the output for a new set of similar data.

## How neural networks work?
a standart neural network is made up of layers of neurons (input-layer, output-layer, hidden-layer), these neurons are core processing units of the network.

- The first layer is called <b>Input Layer</b>, which receives the input.
- The last layers is called <b>Output Layer</b>, which is the final output of network.
- In between existe the <b>Hidden layers</b> which perform the most of the computations requried by our network.
pic

Neurons of one layer are connected to neruons of the next layer through channels. Each of these channels are assigned a numerical value known as weight.
The inputs are multiplied to the corresponding weights and their sum is send as input ot the nerons in the hidden layer.
pic

Each of Neurons in network is associated with a numerical value called the <b>bias</b>, which is added to the input sum. After calculation, the whole value then passed through a threshold function called the activation fuction. the result of the activation function determines if the particular neuron will get activated or not. An activated neuron transmits data to the neurons of the next layer over the channels. In this manner the data is propagated through the netwrok, this is called <b>Forward Propagation</b>.
pic

In the output layer the neurons whit the highest value fires and determines the outpt. The value are basically a probability. Neural network often make a worng prediction at training level. the question is how does the network figure this out.
