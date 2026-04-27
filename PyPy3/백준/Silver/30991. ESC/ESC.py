def differentiate_esc(n):
    coeff_sin2x, coeff_cos2x, coeff_sincosx = 0, 0, 1

    for _ in range(n):
        new_coeff_sin2x = coeff_sin2x + 2 * coeff_sincosx
        new_coeff_cos2x = coeff_cos2x - 2 * coeff_sincosx
        new_coeff_sincosx = coeff_sincosx + coeff_cos2x - coeff_sin2x

        coeff_sin2x, coeff_cos2x, coeff_sincosx = new_coeff_sin2x, new_coeff_cos2x, new_coeff_sincosx

    return coeff_sin2x + coeff_cos2x + coeff_sincosx


print(differentiate_esc(int(input())))
