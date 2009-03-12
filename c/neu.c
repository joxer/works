#define _PRECISION float

typedef struct TypeNeurodo neurodo;
typedef struct TypeSinapsi sinapsi;
typedef struct TypeLayer layer;
typedef struct TypeNN neuralnet;

struct TypeNeuronodo {

  _PRECISION actv_value;
  _PRECISION prop_value;
  sinapsi* in_links[16];
  int num_in_links;
  sinapsi* out_links[16];
  int num_out_links;
  _PRECISION (*actv_func)(_PRECISION prop_value);

};

struct TypeSinapsi {

  _PRECISION delta;
  _PRECISION weight;
  neurodo *in, *out;

};

struct TypeLayer {
  
  neurodo** elements;
  int num_elements;

  void (*update_weights)(layer* lPtr);

};

struct TypeNN {

  int max_epochs;
  _PRECISION l_rate;

  layer* input_layer;
  layer* hidden_layer;
  layer* output_layer;

}
