// Lean compiler output
// Module: ChainProofs.Chain
// Imports: public import Init public meta import Init
#include <lean/lean.h>
#if defined(__clang__)
#pragma clang diagnostic ignored "-Wunused-parameter"
#pragma clang diagnostic ignored "-Wunused-label"
#elif defined(__GNUC__) && !defined(__CLANG__)
#pragma GCC diagnostic ignored "-Wunused-parameter"
#pragma GCC diagnostic ignored "-Wunused-label"
#pragma GCC diagnostic ignored "-Wunused-but-set-variable"
#endif
#ifdef __cplusplus
extern "C" {
#endif
LEAN_EXPORT uint8_t lp_chain_x2dproofs_ChainProofs_linkValid___redArg(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_chain_x2dproofs_ChainProofs_linkValid___redArg___boxed(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT uint8_t lp_chain_x2dproofs_ChainProofs_linkValid(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_chain_x2dproofs_ChainProofs_linkValid___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT uint8_t lp_chain_x2dproofs_ChainProofs_chainValid___redArg(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_chain_x2dproofs_ChainProofs_chainValid___redArg___boxed(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT uint8_t lp_chain_x2dproofs_ChainProofs_chainValid(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_chain_x2dproofs_ChainProofs_chainValid___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_chain_x2dproofs_ChainProofs_nextPrev___redArg(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_chain_x2dproofs_ChainProofs_nextPrev(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_chain_x2dproofs___private_ChainProofs_Chain_0__ChainProofs_linkValid_match__1_splitter___redArg(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_chain_x2dproofs___private_ChainProofs_Chain_0__ChainProofs_linkValid_match__1_splitter(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_chain_x2dproofs___private_ChainProofs_Chain_0__ChainProofs_chainValid_match__1_splitter___redArg(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_chain_x2dproofs___private_ChainProofs_Chain_0__ChainProofs_chainValid_match__1_splitter(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT uint8_t lp_chain_x2dproofs_ChainProofs_linkValid___redArg(lean_object* v_inst_1_, lean_object* v_entryHash_2_, lean_object* v_x_3_, lean_object* v_x_4_){
_start:
{
if (lean_obj_tag(v_x_4_) == 0)
{
uint8_t v___x_5_; 
lean_dec(v_x_3_);
lean_dec(v_entryHash_2_);
lean_dec_ref(v_inst_1_);
v___x_5_ = 1;
return v___x_5_;
}
else
{
lean_object* v_head_6_; lean_object* v_tail_7_; lean_object* v_prev_8_; lean_object* v___x_9_; uint8_t v___x_10_; 
v_head_6_ = lean_ctor_get(v_x_4_, 0);
lean_inc(v_head_6_);
v_tail_7_ = lean_ctor_get(v_x_4_, 1);
lean_inc(v_tail_7_);
lean_dec_ref_known(v_x_4_, 2);
v_prev_8_ = lean_ctor_get(v_head_6_, 1);
lean_inc_ref(v_inst_1_);
lean_inc(v_prev_8_);
v___x_9_ = lean_apply_2(v_inst_1_, v_prev_8_, v_x_3_);
v___x_10_ = lean_unbox(v___x_9_);
if (v___x_10_ == 0)
{
uint8_t v___x_11_; 
lean_dec(v_tail_7_);
lean_dec(v_head_6_);
lean_dec(v_entryHash_2_);
lean_dec_ref(v_inst_1_);
v___x_11_ = lean_unbox(v___x_9_);
return v___x_11_;
}
else
{
lean_object* v___x_12_; 
lean_inc(v_entryHash_2_);
v___x_12_ = lean_apply_1(v_entryHash_2_, v_head_6_);
v_x_3_ = v___x_12_;
v_x_4_ = v_tail_7_;
goto _start;
}
}
}
}
LEAN_EXPORT lean_object* lp_chain_x2dproofs_ChainProofs_linkValid___redArg___boxed(lean_object* v_inst_14_, lean_object* v_entryHash_15_, lean_object* v_x_16_, lean_object* v_x_17_){
_start:
{
uint8_t v_res_18_; lean_object* v_r_19_; 
v_res_18_ = lp_chain_x2dproofs_ChainProofs_linkValid___redArg(v_inst_14_, v_entryHash_15_, v_x_16_, v_x_17_);
v_r_19_ = lean_box(v_res_18_);
return v_r_19_;
}
}
LEAN_EXPORT uint8_t lp_chain_x2dproofs_ChainProofs_linkValid(lean_object* v_D_20_, lean_object* v_H_21_, lean_object* v_inst_22_, lean_object* v_entryHash_23_, lean_object* v_x_24_, lean_object* v_x_25_){
_start:
{
uint8_t v___x_26_; 
v___x_26_ = lp_chain_x2dproofs_ChainProofs_linkValid___redArg(v_inst_22_, v_entryHash_23_, v_x_24_, v_x_25_);
return v___x_26_;
}
}
LEAN_EXPORT lean_object* lp_chain_x2dproofs_ChainProofs_linkValid___boxed(lean_object* v_D_27_, lean_object* v_H_28_, lean_object* v_inst_29_, lean_object* v_entryHash_30_, lean_object* v_x_31_, lean_object* v_x_32_){
_start:
{
uint8_t v_res_33_; lean_object* v_r_34_; 
v_res_33_ = lp_chain_x2dproofs_ChainProofs_linkValid(v_D_27_, v_H_28_, v_inst_29_, v_entryHash_30_, v_x_31_, v_x_32_);
v_r_34_ = lean_box(v_res_33_);
return v_r_34_;
}
}
LEAN_EXPORT uint8_t lp_chain_x2dproofs_ChainProofs_chainValid___redArg(lean_object* v_inst_35_, lean_object* v_entryHash_36_, lean_object* v_H0_37_, lean_object* v_x_38_){
_start:
{
if (lean_obj_tag(v_x_38_) == 0)
{
uint8_t v___x_39_; 
lean_dec(v_H0_37_);
lean_dec(v_entryHash_36_);
lean_dec_ref(v_inst_35_);
v___x_39_ = 1;
return v___x_39_;
}
else
{
lean_object* v_head_40_; lean_object* v_tail_41_; lean_object* v_prev_42_; lean_object* v___x_43_; uint8_t v___x_44_; 
v_head_40_ = lean_ctor_get(v_x_38_, 0);
lean_inc(v_head_40_);
v_tail_41_ = lean_ctor_get(v_x_38_, 1);
lean_inc(v_tail_41_);
lean_dec_ref_known(v_x_38_, 2);
v_prev_42_ = lean_ctor_get(v_head_40_, 1);
lean_inc_ref(v_inst_35_);
lean_inc(v_prev_42_);
v___x_43_ = lean_apply_2(v_inst_35_, v_prev_42_, v_H0_37_);
v___x_44_ = lean_unbox(v___x_43_);
if (v___x_44_ == 0)
{
uint8_t v___x_45_; 
lean_dec(v_tail_41_);
lean_dec(v_head_40_);
lean_dec(v_entryHash_36_);
lean_dec_ref(v_inst_35_);
v___x_45_ = lean_unbox(v___x_43_);
return v___x_45_;
}
else
{
lean_object* v___x_46_; uint8_t v___x_47_; 
lean_inc(v_entryHash_36_);
v___x_46_ = lean_apply_1(v_entryHash_36_, v_head_40_);
v___x_47_ = lp_chain_x2dproofs_ChainProofs_linkValid___redArg(v_inst_35_, v_entryHash_36_, v___x_46_, v_tail_41_);
return v___x_47_;
}
}
}
}
LEAN_EXPORT lean_object* lp_chain_x2dproofs_ChainProofs_chainValid___redArg___boxed(lean_object* v_inst_48_, lean_object* v_entryHash_49_, lean_object* v_H0_50_, lean_object* v_x_51_){
_start:
{
uint8_t v_res_52_; lean_object* v_r_53_; 
v_res_52_ = lp_chain_x2dproofs_ChainProofs_chainValid___redArg(v_inst_48_, v_entryHash_49_, v_H0_50_, v_x_51_);
v_r_53_ = lean_box(v_res_52_);
return v_r_53_;
}
}
LEAN_EXPORT uint8_t lp_chain_x2dproofs_ChainProofs_chainValid(lean_object* v_D_54_, lean_object* v_H_55_, lean_object* v_inst_56_, lean_object* v_entryHash_57_, lean_object* v_H0_58_, lean_object* v_x_59_){
_start:
{
uint8_t v___x_60_; 
v___x_60_ = lp_chain_x2dproofs_ChainProofs_chainValid___redArg(v_inst_56_, v_entryHash_57_, v_H0_58_, v_x_59_);
return v___x_60_;
}
}
LEAN_EXPORT lean_object* lp_chain_x2dproofs_ChainProofs_chainValid___boxed(lean_object* v_D_61_, lean_object* v_H_62_, lean_object* v_inst_63_, lean_object* v_entryHash_64_, lean_object* v_H0_65_, lean_object* v_x_66_){
_start:
{
uint8_t v_res_67_; lean_object* v_r_68_; 
v_res_67_ = lp_chain_x2dproofs_ChainProofs_chainValid(v_D_61_, v_H_62_, v_inst_63_, v_entryHash_64_, v_H0_65_, v_x_66_);
v_r_68_ = lean_box(v_res_67_);
return v_r_68_;
}
}
LEAN_EXPORT lean_object* lp_chain_x2dproofs_ChainProofs_nextPrev___redArg(lean_object* v_entryHash_69_, lean_object* v_ph_70_, lean_object* v_x_71_){
_start:
{
if (lean_obj_tag(v_x_71_) == 0)
{
lean_dec(v_entryHash_69_);
return v_ph_70_;
}
else
{
lean_object* v_head_72_; lean_object* v_tail_73_; lean_object* v___x_74_; 
lean_dec(v_ph_70_);
v_head_72_ = lean_ctor_get(v_x_71_, 0);
lean_inc(v_head_72_);
v_tail_73_ = lean_ctor_get(v_x_71_, 1);
lean_inc(v_tail_73_);
lean_dec_ref_known(v_x_71_, 2);
lean_inc(v_entryHash_69_);
v___x_74_ = lean_apply_1(v_entryHash_69_, v_head_72_);
v_ph_70_ = v___x_74_;
v_x_71_ = v_tail_73_;
goto _start;
}
}
}
LEAN_EXPORT lean_object* lp_chain_x2dproofs_ChainProofs_nextPrev(lean_object* v_D_76_, lean_object* v_H_77_, lean_object* v_entryHash_78_, lean_object* v_ph_79_, lean_object* v_x_80_){
_start:
{
lean_object* v___x_81_; 
v___x_81_ = lp_chain_x2dproofs_ChainProofs_nextPrev___redArg(v_entryHash_78_, v_ph_79_, v_x_80_);
return v___x_81_;
}
}
LEAN_EXPORT lean_object* lp_chain_x2dproofs___private_ChainProofs_Chain_0__ChainProofs_linkValid_match__1_splitter___redArg(lean_object* v_x_82_, lean_object* v_x_83_, lean_object* v_h__1_84_, lean_object* v_h__2_85_){
_start:
{
if (lean_obj_tag(v_x_83_) == 0)
{
lean_object* v___x_86_; 
lean_dec(v_h__2_85_);
v___x_86_ = lean_apply_1(v_h__1_84_, v_x_82_);
return v___x_86_;
}
else
{
lean_object* v_head_87_; lean_object* v_tail_88_; lean_object* v___x_89_; 
lean_dec(v_h__1_84_);
v_head_87_ = lean_ctor_get(v_x_83_, 0);
lean_inc(v_head_87_);
v_tail_88_ = lean_ctor_get(v_x_83_, 1);
lean_inc(v_tail_88_);
lean_dec_ref_known(v_x_83_, 2);
v___x_89_ = lean_apply_3(v_h__2_85_, v_x_82_, v_head_87_, v_tail_88_);
return v___x_89_;
}
}
}
LEAN_EXPORT lean_object* lp_chain_x2dproofs___private_ChainProofs_Chain_0__ChainProofs_linkValid_match__1_splitter(lean_object* v_D_90_, lean_object* v_H_91_, lean_object* v_motive_92_, lean_object* v_x_93_, lean_object* v_x_94_, lean_object* v_h__1_95_, lean_object* v_h__2_96_){
_start:
{
if (lean_obj_tag(v_x_94_) == 0)
{
lean_object* v___x_97_; 
lean_dec(v_h__2_96_);
v___x_97_ = lean_apply_1(v_h__1_95_, v_x_93_);
return v___x_97_;
}
else
{
lean_object* v_head_98_; lean_object* v_tail_99_; lean_object* v___x_100_; 
lean_dec(v_h__1_95_);
v_head_98_ = lean_ctor_get(v_x_94_, 0);
lean_inc(v_head_98_);
v_tail_99_ = lean_ctor_get(v_x_94_, 1);
lean_inc(v_tail_99_);
lean_dec_ref_known(v_x_94_, 2);
v___x_100_ = lean_apply_3(v_h__2_96_, v_x_93_, v_head_98_, v_tail_99_);
return v___x_100_;
}
}
}
LEAN_EXPORT lean_object* lp_chain_x2dproofs___private_ChainProofs_Chain_0__ChainProofs_chainValid_match__1_splitter___redArg(lean_object* v_x_101_, lean_object* v_h__1_102_, lean_object* v_h__2_103_){
_start:
{
if (lean_obj_tag(v_x_101_) == 0)
{
lean_object* v___x_104_; lean_object* v___x_105_; 
lean_dec(v_h__2_103_);
v___x_104_ = lean_box(0);
v___x_105_ = lean_apply_1(v_h__1_102_, v___x_104_);
return v___x_105_;
}
else
{
lean_object* v_head_106_; lean_object* v_tail_107_; lean_object* v___x_108_; 
lean_dec(v_h__1_102_);
v_head_106_ = lean_ctor_get(v_x_101_, 0);
lean_inc(v_head_106_);
v_tail_107_ = lean_ctor_get(v_x_101_, 1);
lean_inc(v_tail_107_);
lean_dec_ref_known(v_x_101_, 2);
v___x_108_ = lean_apply_2(v_h__2_103_, v_head_106_, v_tail_107_);
return v___x_108_;
}
}
}
LEAN_EXPORT lean_object* lp_chain_x2dproofs___private_ChainProofs_Chain_0__ChainProofs_chainValid_match__1_splitter(lean_object* v_D_109_, lean_object* v_H_110_, lean_object* v_motive_111_, lean_object* v_x_112_, lean_object* v_h__1_113_, lean_object* v_h__2_114_){
_start:
{
if (lean_obj_tag(v_x_112_) == 0)
{
lean_object* v___x_115_; lean_object* v___x_116_; 
lean_dec(v_h__2_114_);
v___x_115_ = lean_box(0);
v___x_116_ = lean_apply_1(v_h__1_113_, v___x_115_);
return v___x_116_;
}
else
{
lean_object* v_head_117_; lean_object* v_tail_118_; lean_object* v___x_119_; 
lean_dec(v_h__1_113_);
v_head_117_ = lean_ctor_get(v_x_112_, 0);
lean_inc(v_head_117_);
v_tail_118_ = lean_ctor_get(v_x_112_, 1);
lean_inc(v_tail_118_);
lean_dec_ref_known(v_x_112_, 2);
v___x_119_ = lean_apply_2(v_h__2_114_, v_head_117_, v_tail_118_);
return v___x_119_;
}
}
}
lean_object* initialize_Init(uint8_t builtin);
lean_object* initialize_Init(uint8_t builtin);
void lean_initialize_runtime_module();
static bool _G_initialized = false;
LEAN_EXPORT lean_object* initialize_chain_x2dproofs_ChainProofs_Chain(uint8_t builtin) {
lean_object * res;
if (_G_initialized) return lean_io_result_mk_ok(lean_box(0));
_G_initialized = true;
lean_initialize_runtime_module();
res = initialize_Init(builtin);
if (lean_io_result_is_error(res)) return res;
lean_dec_ref(res);
res = initialize_Init(builtin);
if (lean_io_result_is_error(res)) return res;
lean_dec_ref(res);
return lean_io_result_mk_ok(lean_box(0));
}
#ifdef __cplusplus
}
#endif
