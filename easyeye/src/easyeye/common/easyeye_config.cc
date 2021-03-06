#include "easyeye_config.h"

using namespace easyeye;

Config::Config(){
    
}

IrisFinderConfig::IrisFinderConfig() 
    : CircleFinderConfig(),
        max_pupil_center_offset_divisor(4),
        max_pupil_center_offset_(AUTO_MAX_PUPIL_CENTER_OFFSET)
{

    max_radius_factor = 82;
}

int IrisFinderConfig::max_pupil_center_offset()
{
    if (max_pupil_center_offset_ == AUTO_MAX_PUPIL_CENTER_OFFSET) {
        return max_radius() / max_pupil_center_offset_divisor;
    } else {
        return max_pupil_center_offset_;
    }
}

PupilFinderConfig::PupilFinderConfig() 
    : CircleFinderConfig()
{
    max_radius_factor = (42);
}

CircleFinderConfig::CircleFinderConfig()
    : iris_image_type(NIR_IRIS_STILL), nScale(NSCALE_AUTO), max_radius_factor(82)
{
    
}

int CircleFinderConfig::max_radius()
{
    return nScale * max_radius_factor;
}

// cvSmooth's default sigma is calculated based on kernel size 
// http://docs.opencv.org/trunk/modules/imgproc/doc/filtering.html?highlight=smooth#smooth
GaussConfig::GaussConfig() 
    : Config(),
        kernel_width(31), kernel_height(15), sigma_x(0.3 * (31 / 2 - 1) + 0.8)
{
}

GaussConfig::GaussConfig(int kernel_width_, int kernel_height_, double sigma_x_)
    : Config(),
        kernel_width(kernel_width_),
        kernel_height(kernel_height_),
        sigma_x(sigma_x_)
{
}

EyelidFinderConfig::EyelidFinderConfig()
: Config(), 
        iris_image_type(NIR_IRIS_STILL), 
        gauss_config(31, 15, 0.3 * (31 / 2 - 1) + 0.8), 
        min_contour_count(70),
        method(METHOD_ELLIPSE_CONTOUR),
        upper_search_region_iris_height_proportion(0.5f),
        lower_search_region_iris_height_proportion(0.2f),
        lateral_search_region_iris_width_proportion(0.25f),
        upper_parabola_vertex_min_relative(0.2f, 0.0f),
        upper_parabola_vertex_max_relative(0.8f, 0.9f),
        lower_parabola_vertex_min_relative(0.2f, 0.1f),
        lower_parabola_vertex_max_relative(0.8f, 1.0f),
        upper_parabola_a_range(0.001f, 0.02f, 0.0025f),
        lower_parabola_a_range(-0.02f, -0.001f, 0.0025f), 
        upper_parabola_theta_range(M_PI / -10.0, M_PI / 10.0, M_PI / 50.0),
        lower_parabola_theta_range(M_PI / -10.0, M_PI / 10.0, M_PI / 50.0), 
        eyelid_hough_dilation_kernel_size(3), 
        upper_eyelid_hough_vote_total_min(255.0f * 100), 
        lower_eyelid_hough_vote_total_min(255.0f * 100)
{
}

ExtremaNoiseFinderConfig::ExtremaNoiseFinderConfig()
    : Config(), 
        highlight_threshold(250), lowlight_threshold(3)
{
}

RangeParams::RangeParams()
        : minimum(0), maximum(0), step(0)
{
}

RangeParams::RangeParams(double minimum_, double maximum_, double step_)
        : minimum(minimum_), maximum(maximum_), step(step_)
{
}

