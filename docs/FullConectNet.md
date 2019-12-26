## Full Conection Neural NetWork Tools Developing Document
## 1.Introduce
## 2.class Layer
In this project, my mainly purpose is the
of implementation the forward propagation process of data, which is used to 
produce the results of the trained network
structure.Therefore, in this project, there is not
including backward process, learning ratio or other
model train related work.  

***Note*** in the following contains, there are no comment
of some variables, which means those variance may 
not used in forward propagation process.   
### 2.1 Member Variances

int stride;//which would be used in convolution neural network  

int batch;//how many images(data) be trained in one round.  

int h, w, c;//input image's width, height and channels  

int input_size;//the input size of data(excluding batch),input_size = w*h*c  

int group_size;//  

int out_w, out_h, out_c;//which would be used in convolution neural network  

int output_size;// output_size = out_w*out_h*out_c(excluding batch)  

double *output_data;//including batch  

double *delta;//  

double *float;//  

double *cost;// 

double *weight;//the weight of this layer  

double *weight_update;//  

bool bias;//the bias of each input  

double biases;//a group of biases  

double bias_update;//  


  