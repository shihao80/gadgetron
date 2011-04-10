#ifndef CGOPERATORCARTESIANSENSE_H
#define CGOPERATORCARTESIANSENSE_H

#include "cgOperatorSense.h"

class cgOperatorCartesianSense : public cgOperatorSense
{

 public:
  cgOperatorCartesianSense()
    : cgOperatorSense()
    , idx_(0)
    { }

  virtual int mult_M(cuNDArray<float2>* in, cuNDArray<float2>* out, bool accumulate = false);
  virtual int mult_MH(cuNDArray<float2>* in, cuNDArray<float2>* out, bool accumulate = false);
  //virtual int mult_MH_M(cuNDArray<float2>* in, cuNDArray<float2>* out, bool accumulate = false);

  virtual int set_csm(cuNDArray<float2>* csm) {
    if (csm != 0) {
      csm_ = csm;
      coils_ = csm_->get_size(csm_->get_number_of_dimensions()-1);
      dimensions_ = csm->get_dimensions();
      dimensions_.pop_back();
    }
    return 0;
  }


  virtual int set_sampling_indices(cuNDArray<unsigned int>* idx) {
    if (idx) {
      idx_ = idx;
      samples_ = idx_->get_number_of_elements();
      dimensions_out_.clear();
      dimensions_out_.push_back(samples_);
      dimensions_out_.push_back(coils_);
    }
    return 0;
  }

 protected:
  cuNDArray<unsigned int>* idx_;
};


#endif //CGOPERATORCARTESIANSENSE_H
