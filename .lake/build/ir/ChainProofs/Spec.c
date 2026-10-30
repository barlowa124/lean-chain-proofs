// Lean compiler output
// Module: ChainProofs.Spec
// Imports: public import Init public meta import Init public import ChainProofs.Chain
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
lean_object* lean_nat_mul(lean_object*, lean_object*);
lean_object* lean_nat_add(lean_object*, lean_object*);
lean_object* l_List_appendTR___redArg(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_chain_x2dproofs_ChainProofs_demoHash(lean_object*);
LEAN_EXPORT lean_object* lp_chain_x2dproofs_ChainProofs_demoHash___boxed(lean_object*);
LEAN_EXPORT lean_object* lp_chain_x2dproofs_ChainProofs_H0;
static const lean_ctor_object lp_chain_x2dproofs_ChainProofs_e1___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 0}, .m_objs = {((lean_object*)(((size_t)(11) << 1) | 1)),((lean_object*)(((size_t)(0) << 1) | 1))}};
static const lean_object* lp_chain_x2dproofs_ChainProofs_e1___closed__0 = (const lean_object*)&lp_chain_x2dproofs_ChainProofs_e1___closed__0_value;
LEAN_EXPORT const lean_object* lp_chain_x2dproofs_ChainProofs_e1 = (const lean_object*)&lp_chain_x2dproofs_ChainProofs_e1___closed__0_value;
static lean_once_cell_t lp_chain_x2dproofs_ChainProofs_e2___closed__0_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_chain_x2dproofs_ChainProofs_e2___closed__0;
static lean_once_cell_t lp_chain_x2dproofs_ChainProofs_e2___closed__1_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_chain_x2dproofs_ChainProofs_e2___closed__1;
LEAN_EXPORT lean_object* lp_chain_x2dproofs_ChainProofs_e2;
static lean_once_cell_t lp_chain_x2dproofs_ChainProofs_e3___closed__0_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_chain_x2dproofs_ChainProofs_e3___closed__0;
static lean_once_cell_t lp_chain_x2dproofs_ChainProofs_e3___closed__1_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_chain_x2dproofs_ChainProofs_e3___closed__1;
LEAN_EXPORT lean_object* lp_chain_x2dproofs_ChainProofs_e3;
static lean_once_cell_t lp_chain_x2dproofs_ChainProofs_good___closed__0_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_chain_x2dproofs_ChainProofs_good___closed__0;
static lean_once_cell_t lp_chain_x2dproofs_ChainProofs_good___closed__1_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_chain_x2dproofs_ChainProofs_good___closed__1;
static lean_once_cell_t lp_chain_x2dproofs_ChainProofs_good___closed__2_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_chain_x2dproofs_ChainProofs_good___closed__2;
LEAN_EXPORT lean_object* lp_chain_x2dproofs_ChainProofs_good;
static lean_once_cell_t lp_chain_x2dproofs_ChainProofs_tampered___closed__0_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_chain_x2dproofs_ChainProofs_tampered___closed__0;
static lean_once_cell_t lp_chain_x2dproofs_ChainProofs_tampered___closed__1_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_chain_x2dproofs_ChainProofs_tampered___closed__1;
static lean_once_cell_t lp_chain_x2dproofs_ChainProofs_tampered___closed__2_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_chain_x2dproofs_ChainProofs_tampered___closed__2;
LEAN_EXPORT lean_object* lp_chain_x2dproofs_ChainProofs_tampered;
static lean_once_cell_t lp_chain_x2dproofs_ChainProofs_deleted___closed__0_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_chain_x2dproofs_ChainProofs_deleted___closed__0;
LEAN_EXPORT lean_object* lp_chain_x2dproofs_ChainProofs_deleted;
static lean_once_cell_t lp_chain_x2dproofs_ChainProofs_appended___closed__0_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_chain_x2dproofs_ChainProofs_appended___closed__0;
static lean_once_cell_t lp_chain_x2dproofs_ChainProofs_appended___closed__1_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_chain_x2dproofs_ChainProofs_appended___closed__1;
static lean_once_cell_t lp_chain_x2dproofs_ChainProofs_appended___closed__2_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_chain_x2dproofs_ChainProofs_appended___closed__2;
static lean_once_cell_t lp_chain_x2dproofs_ChainProofs_appended___closed__3_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_chain_x2dproofs_ChainProofs_appended___closed__3;
LEAN_EXPORT lean_object* lp_chain_x2dproofs_ChainProofs_appended;
static const lean_ctor_object lp_chain_x2dproofs_ChainProofs_badAppend___closed__0_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 0}, .m_objs = {((lean_object*)(((size_t)(44) << 1) | 1)),((lean_object*)(((size_t)(0) << 1) | 1))}};
static const lean_object* lp_chain_x2dproofs_ChainProofs_badAppend___closed__0 = (const lean_object*)&lp_chain_x2dproofs_ChainProofs_badAppend___closed__0_value;
static const lean_ctor_object lp_chain_x2dproofs_ChainProofs_badAppend___closed__1_value = {.m_header = {.m_rc = 0, .m_cs_sz = sizeof(lean_ctor_object) + sizeof(void*)*2 + 0, .m_other = 2, .m_tag = 1}, .m_objs = {((lean_object*)&lp_chain_x2dproofs_ChainProofs_badAppend___closed__0_value),((lean_object*)(((size_t)(0) << 1) | 1))}};
static const lean_object* lp_chain_x2dproofs_ChainProofs_badAppend___closed__1 = (const lean_object*)&lp_chain_x2dproofs_ChainProofs_badAppend___closed__1_value;
static lean_once_cell_t lp_chain_x2dproofs_ChainProofs_badAppend___closed__2_once = LEAN_ONCE_CELL_INITIALIZER;
static lean_object* lp_chain_x2dproofs_ChainProofs_badAppend___closed__2;
LEAN_EXPORT lean_object* lp_chain_x2dproofs_ChainProofs_badAppend;
LEAN_EXPORT lean_object* lp_chain_x2dproofs_ChainProofs_demoHash(lean_object* v_x_1_){
_start:
{
lean_object* v_payload_2_; lean_object* v_prev_3_; lean_object* v___x_4_; lean_object* v___x_5_; lean_object* v___x_6_; 
v_payload_2_ = lean_ctor_get(v_x_1_, 0);
v_prev_3_ = lean_ctor_get(v_x_1_, 1);
v___x_4_ = lean_unsigned_to_nat(104729u);
v___x_5_ = lean_nat_mul(v_prev_3_, v___x_4_);
v___x_6_ = lean_nat_add(v___x_5_, v_payload_2_);
lean_dec(v___x_5_);
return v___x_6_;
}
}
LEAN_EXPORT lean_object* lp_chain_x2dproofs_ChainProofs_demoHash___boxed(lean_object* v_x_7_){
_start:
{
lean_object* v_res_8_; 
v_res_8_ = lp_chain_x2dproofs_ChainProofs_demoHash(v_x_7_);
lean_dec_ref(v_x_7_);
return v_res_8_;
}
}
static lean_object* _init_lp_chain_x2dproofs_ChainProofs_H0(void){
_start:
{
lean_object* v___x_9_; 
v___x_9_ = lean_unsigned_to_nat(0u);
return v___x_9_;
}
}
static lean_object* _init_lp_chain_x2dproofs_ChainProofs_e2___closed__0(void){
_start:
{
lean_object* v___x_14_; lean_object* v___x_15_; 
v___x_14_ = ((lean_object*)(lp_chain_x2dproofs_ChainProofs_e1));
v___x_15_ = lp_chain_x2dproofs_ChainProofs_demoHash(v___x_14_);
return v___x_15_;
}
}
static lean_object* _init_lp_chain_x2dproofs_ChainProofs_e2___closed__1(void){
_start:
{
lean_object* v___x_16_; lean_object* v___x_17_; lean_object* v___x_18_; 
v___x_16_ = lean_obj_once(&lp_chain_x2dproofs_ChainProofs_e2___closed__0, &lp_chain_x2dproofs_ChainProofs_e2___closed__0_once, _init_lp_chain_x2dproofs_ChainProofs_e2___closed__0);
v___x_17_ = lean_unsigned_to_nat(22u);
v___x_18_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_18_, 0, v___x_17_);
lean_ctor_set(v___x_18_, 1, v___x_16_);
return v___x_18_;
}
}
static lean_object* _init_lp_chain_x2dproofs_ChainProofs_e2(void){
_start:
{
lean_object* v___x_19_; 
v___x_19_ = lean_obj_once(&lp_chain_x2dproofs_ChainProofs_e2___closed__1, &lp_chain_x2dproofs_ChainProofs_e2___closed__1_once, _init_lp_chain_x2dproofs_ChainProofs_e2___closed__1);
return v___x_19_;
}
}
static lean_object* _init_lp_chain_x2dproofs_ChainProofs_e3___closed__0(void){
_start:
{
lean_object* v___x_20_; lean_object* v___x_21_; 
v___x_20_ = lp_chain_x2dproofs_ChainProofs_e2;
v___x_21_ = lp_chain_x2dproofs_ChainProofs_demoHash(v___x_20_);
return v___x_21_;
}
}
static lean_object* _init_lp_chain_x2dproofs_ChainProofs_e3___closed__1(void){
_start:
{
lean_object* v___x_22_; lean_object* v___x_23_; lean_object* v___x_24_; 
v___x_22_ = lean_obj_once(&lp_chain_x2dproofs_ChainProofs_e3___closed__0, &lp_chain_x2dproofs_ChainProofs_e3___closed__0_once, _init_lp_chain_x2dproofs_ChainProofs_e3___closed__0);
v___x_23_ = lean_unsigned_to_nat(33u);
v___x_24_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_24_, 0, v___x_23_);
lean_ctor_set(v___x_24_, 1, v___x_22_);
return v___x_24_;
}
}
static lean_object* _init_lp_chain_x2dproofs_ChainProofs_e3(void){
_start:
{
lean_object* v___x_25_; 
v___x_25_ = lean_obj_once(&lp_chain_x2dproofs_ChainProofs_e3___closed__1, &lp_chain_x2dproofs_ChainProofs_e3___closed__1_once, _init_lp_chain_x2dproofs_ChainProofs_e3___closed__1);
return v___x_25_;
}
}
static lean_object* _init_lp_chain_x2dproofs_ChainProofs_good___closed__0(void){
_start:
{
lean_object* v___x_26_; lean_object* v___x_27_; lean_object* v___x_28_; 
v___x_26_ = lean_box(0);
v___x_27_ = lp_chain_x2dproofs_ChainProofs_e3;
v___x_28_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_28_, 0, v___x_27_);
lean_ctor_set(v___x_28_, 1, v___x_26_);
return v___x_28_;
}
}
static lean_object* _init_lp_chain_x2dproofs_ChainProofs_good___closed__1(void){
_start:
{
lean_object* v___x_29_; lean_object* v___x_30_; lean_object* v___x_31_; 
v___x_29_ = lean_obj_once(&lp_chain_x2dproofs_ChainProofs_good___closed__0, &lp_chain_x2dproofs_ChainProofs_good___closed__0_once, _init_lp_chain_x2dproofs_ChainProofs_good___closed__0);
v___x_30_ = lp_chain_x2dproofs_ChainProofs_e2;
v___x_31_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_31_, 0, v___x_30_);
lean_ctor_set(v___x_31_, 1, v___x_29_);
return v___x_31_;
}
}
static lean_object* _init_lp_chain_x2dproofs_ChainProofs_good___closed__2(void){
_start:
{
lean_object* v___x_32_; lean_object* v___x_33_; lean_object* v___x_34_; 
v___x_32_ = lean_obj_once(&lp_chain_x2dproofs_ChainProofs_good___closed__1, &lp_chain_x2dproofs_ChainProofs_good___closed__1_once, _init_lp_chain_x2dproofs_ChainProofs_good___closed__1);
v___x_33_ = ((lean_object*)(lp_chain_x2dproofs_ChainProofs_e1));
v___x_34_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_34_, 0, v___x_33_);
lean_ctor_set(v___x_34_, 1, v___x_32_);
return v___x_34_;
}
}
static lean_object* _init_lp_chain_x2dproofs_ChainProofs_good(void){
_start:
{
lean_object* v___x_35_; 
v___x_35_ = lean_obj_once(&lp_chain_x2dproofs_ChainProofs_good___closed__2, &lp_chain_x2dproofs_ChainProofs_good___closed__2_once, _init_lp_chain_x2dproofs_ChainProofs_good___closed__2);
return v___x_35_;
}
}
static lean_object* _init_lp_chain_x2dproofs_ChainProofs_tampered___closed__0(void){
_start:
{
lean_object* v___x_36_; lean_object* v___x_37_; lean_object* v___x_38_; 
v___x_36_ = lean_obj_once(&lp_chain_x2dproofs_ChainProofs_e2___closed__0, &lp_chain_x2dproofs_ChainProofs_e2___closed__0_once, _init_lp_chain_x2dproofs_ChainProofs_e2___closed__0);
v___x_37_ = lean_unsigned_to_nat(23u);
v___x_38_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_38_, 0, v___x_37_);
lean_ctor_set(v___x_38_, 1, v___x_36_);
return v___x_38_;
}
}
static lean_object* _init_lp_chain_x2dproofs_ChainProofs_tampered___closed__1(void){
_start:
{
lean_object* v___x_39_; lean_object* v___x_40_; lean_object* v___x_41_; 
v___x_39_ = lean_obj_once(&lp_chain_x2dproofs_ChainProofs_good___closed__0, &lp_chain_x2dproofs_ChainProofs_good___closed__0_once, _init_lp_chain_x2dproofs_ChainProofs_good___closed__0);
v___x_40_ = lean_obj_once(&lp_chain_x2dproofs_ChainProofs_tampered___closed__0, &lp_chain_x2dproofs_ChainProofs_tampered___closed__0_once, _init_lp_chain_x2dproofs_ChainProofs_tampered___closed__0);
v___x_41_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_41_, 0, v___x_40_);
lean_ctor_set(v___x_41_, 1, v___x_39_);
return v___x_41_;
}
}
static lean_object* _init_lp_chain_x2dproofs_ChainProofs_tampered___closed__2(void){
_start:
{
lean_object* v___x_42_; lean_object* v___x_43_; lean_object* v___x_44_; 
v___x_42_ = lean_obj_once(&lp_chain_x2dproofs_ChainProofs_tampered___closed__1, &lp_chain_x2dproofs_ChainProofs_tampered___closed__1_once, _init_lp_chain_x2dproofs_ChainProofs_tampered___closed__1);
v___x_43_ = ((lean_object*)(lp_chain_x2dproofs_ChainProofs_e1));
v___x_44_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_44_, 0, v___x_43_);
lean_ctor_set(v___x_44_, 1, v___x_42_);
return v___x_44_;
}
}
static lean_object* _init_lp_chain_x2dproofs_ChainProofs_tampered(void){
_start:
{
lean_object* v___x_45_; 
v___x_45_ = lean_obj_once(&lp_chain_x2dproofs_ChainProofs_tampered___closed__2, &lp_chain_x2dproofs_ChainProofs_tampered___closed__2_once, _init_lp_chain_x2dproofs_ChainProofs_tampered___closed__2);
return v___x_45_;
}
}
static lean_object* _init_lp_chain_x2dproofs_ChainProofs_deleted___closed__0(void){
_start:
{
lean_object* v___x_46_; lean_object* v___x_47_; lean_object* v___x_48_; 
v___x_46_ = lean_obj_once(&lp_chain_x2dproofs_ChainProofs_good___closed__0, &lp_chain_x2dproofs_ChainProofs_good___closed__0_once, _init_lp_chain_x2dproofs_ChainProofs_good___closed__0);
v___x_47_ = ((lean_object*)(lp_chain_x2dproofs_ChainProofs_e1));
v___x_48_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_48_, 0, v___x_47_);
lean_ctor_set(v___x_48_, 1, v___x_46_);
return v___x_48_;
}
}
static lean_object* _init_lp_chain_x2dproofs_ChainProofs_deleted(void){
_start:
{
lean_object* v___x_49_; 
v___x_49_ = lean_obj_once(&lp_chain_x2dproofs_ChainProofs_deleted___closed__0, &lp_chain_x2dproofs_ChainProofs_deleted___closed__0_once, _init_lp_chain_x2dproofs_ChainProofs_deleted___closed__0);
return v___x_49_;
}
}
static lean_object* _init_lp_chain_x2dproofs_ChainProofs_appended___closed__0(void){
_start:
{
lean_object* v___x_50_; lean_object* v___x_51_; 
v___x_50_ = lp_chain_x2dproofs_ChainProofs_e3;
v___x_51_ = lp_chain_x2dproofs_ChainProofs_demoHash(v___x_50_);
return v___x_51_;
}
}
static lean_object* _init_lp_chain_x2dproofs_ChainProofs_appended___closed__1(void){
_start:
{
lean_object* v___x_52_; lean_object* v___x_53_; lean_object* v___x_54_; 
v___x_52_ = lean_obj_once(&lp_chain_x2dproofs_ChainProofs_appended___closed__0, &lp_chain_x2dproofs_ChainProofs_appended___closed__0_once, _init_lp_chain_x2dproofs_ChainProofs_appended___closed__0);
v___x_53_ = lean_unsigned_to_nat(44u);
v___x_54_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_54_, 0, v___x_53_);
lean_ctor_set(v___x_54_, 1, v___x_52_);
return v___x_54_;
}
}
static lean_object* _init_lp_chain_x2dproofs_ChainProofs_appended___closed__2(void){
_start:
{
lean_object* v___x_55_; lean_object* v___x_56_; lean_object* v___x_57_; 
v___x_55_ = lean_box(0);
v___x_56_ = lean_obj_once(&lp_chain_x2dproofs_ChainProofs_appended___closed__1, &lp_chain_x2dproofs_ChainProofs_appended___closed__1_once, _init_lp_chain_x2dproofs_ChainProofs_appended___closed__1);
v___x_57_ = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(v___x_57_, 0, v___x_56_);
lean_ctor_set(v___x_57_, 1, v___x_55_);
return v___x_57_;
}
}
static lean_object* _init_lp_chain_x2dproofs_ChainProofs_appended___closed__3(void){
_start:
{
lean_object* v___x_58_; lean_object* v___x_59_; lean_object* v___x_60_; 
v___x_58_ = lean_obj_once(&lp_chain_x2dproofs_ChainProofs_appended___closed__2, &lp_chain_x2dproofs_ChainProofs_appended___closed__2_once, _init_lp_chain_x2dproofs_ChainProofs_appended___closed__2);
v___x_59_ = lp_chain_x2dproofs_ChainProofs_good;
v___x_60_ = l_List_appendTR___redArg(v___x_59_, v___x_58_);
return v___x_60_;
}
}
static lean_object* _init_lp_chain_x2dproofs_ChainProofs_appended(void){
_start:
{
lean_object* v___x_61_; 
v___x_61_ = lean_obj_once(&lp_chain_x2dproofs_ChainProofs_appended___closed__3, &lp_chain_x2dproofs_ChainProofs_appended___closed__3_once, _init_lp_chain_x2dproofs_ChainProofs_appended___closed__3);
return v___x_61_;
}
}
static lean_object* _init_lp_chain_x2dproofs_ChainProofs_badAppend___closed__2(void){
_start:
{
lean_object* v___x_68_; lean_object* v___x_69_; lean_object* v___x_70_; 
v___x_68_ = ((lean_object*)(lp_chain_x2dproofs_ChainProofs_badAppend___closed__1));
v___x_69_ = lp_chain_x2dproofs_ChainProofs_good;
v___x_70_ = l_List_appendTR___redArg(v___x_69_, v___x_68_);
return v___x_70_;
}
}
static lean_object* _init_lp_chain_x2dproofs_ChainProofs_badAppend(void){
_start:
{
lean_object* v___x_71_; 
v___x_71_ = lean_obj_once(&lp_chain_x2dproofs_ChainProofs_badAppend___closed__2, &lp_chain_x2dproofs_ChainProofs_badAppend___closed__2_once, _init_lp_chain_x2dproofs_ChainProofs_badAppend___closed__2);
return v___x_71_;
}
}
lean_object* initialize_Init(uint8_t builtin);
lean_object* initialize_Init(uint8_t builtin);
lean_object* initialize_chain_x2dproofs_ChainProofs_Chain(uint8_t builtin);
void lean_initialize_runtime_module();
static bool _G_initialized = false;
LEAN_EXPORT lean_object* initialize_chain_x2dproofs_ChainProofs_Spec(uint8_t builtin) {
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
res = initialize_chain_x2dproofs_ChainProofs_Chain(builtin);
if (lean_io_result_is_error(res)) return res;
lean_dec_ref(res);
lp_chain_x2dproofs_ChainProofs_H0 = _init_lp_chain_x2dproofs_ChainProofs_H0();
lean_mark_persistent(lp_chain_x2dproofs_ChainProofs_H0);
lp_chain_x2dproofs_ChainProofs_e2 = _init_lp_chain_x2dproofs_ChainProofs_e2();
lean_mark_persistent(lp_chain_x2dproofs_ChainProofs_e2);
lp_chain_x2dproofs_ChainProofs_e3 = _init_lp_chain_x2dproofs_ChainProofs_e3();
lean_mark_persistent(lp_chain_x2dproofs_ChainProofs_e3);
lp_chain_x2dproofs_ChainProofs_good = _init_lp_chain_x2dproofs_ChainProofs_good();
lean_mark_persistent(lp_chain_x2dproofs_ChainProofs_good);
lp_chain_x2dproofs_ChainProofs_tampered = _init_lp_chain_x2dproofs_ChainProofs_tampered();
lean_mark_persistent(lp_chain_x2dproofs_ChainProofs_tampered);
lp_chain_x2dproofs_ChainProofs_deleted = _init_lp_chain_x2dproofs_ChainProofs_deleted();
lean_mark_persistent(lp_chain_x2dproofs_ChainProofs_deleted);
lp_chain_x2dproofs_ChainProofs_appended = _init_lp_chain_x2dproofs_ChainProofs_appended();
lean_mark_persistent(lp_chain_x2dproofs_ChainProofs_appended);
lp_chain_x2dproofs_ChainProofs_badAppend = _init_lp_chain_x2dproofs_ChainProofs_badAppend();
lean_mark_persistent(lp_chain_x2dproofs_ChainProofs_badAppend);
return lean_io_result_mk_ok(lean_box(0));
}
#ifdef __cplusplus
}
#endif
