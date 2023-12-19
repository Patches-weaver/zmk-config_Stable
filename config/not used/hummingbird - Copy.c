/*
 * Copyright (c) 2020 The ZMK Contributors
 *
 * SPDX-License-Identifier: MIT
 */

#include <behaviors.dtsi>
#include <dt-bindings/zmk/keys.h>

#define DEF_L 0
#define NAV_L 1
#define NUM_L 2
#define SYM_L 3
#define OTH_L 4

/*                KEY POSITIONS

  ╭────────────────────╮ ╭────────────────────╮
  │  0   1   2   3   4 │ │  5   6   7   8   9 │
  │ 10  11  12  13  14 │ │ 15  16  17  18  19 │
  │     20  21  22     │ │     23  24  25     │
  ╰───────────╮ 26  27 │ │ 28  29 ╭───────────╯
              ╰────────╯ ╰────────╯            */

// Using layer taps on thumbs, having quick tap as well helps w/ repeating space/backspace
&lt { quick_tap_ms = <200>; };

/ {
    behaviors {
        hm: homerow_mods {
            compatible = "zmk,behavior-hold-tap";
            label = "homerow mods";
            #binding-cells = <2>;
            tapping_term_ms = <225>;
            flavor = "tap-preferred";
            bindings = <&kp>, <&kp>;
        };
    };

    combos {
        compatible = "zmk,combos";
        combo_z {
            timeout-ms = <50>;
            key-positions = <0 10>;
            bindings = <&kp Z>;
        };
        combo_b {
            timeout-ms = <50>;
            key-positions = <4 14>;
            bindings = <&kp B>;
        };

        combo_n {
            timeout-ms = <50>;
            key-positions = <5 15>;
            bindings = <&kp N>;
        };
    };
};

/ {
    keymap {
        compatible = "zmk,keymap";

        default_layer {
            bindings = <
                &kp C       &kp B       &kp H           &kp G           &kp K           &kp COMMA           &kp DOT         &kp I           &kp O       &kp P
                &hm LGUI P  &hm LALT S  &hm LCTRL N     &hm LSHFT F     &kp G           &kp H               &hm RSHFT J     &hm RCTRL K     &hm RALT L  &hm RGUI SEMI
                            &kp X       &kp C           &kp V                                               &kp M           &kp COMMA       &kp DOT
                                                        &lt NAV_L TAB   &kp RET         &lt NUM_L SPACE     &lt SYM_L BKSP
            >;
        };

        nav_layer {
            label = "Nav";
            bindings = <
                &trans     &trans     &trans      &trans          &trans       &trans           &kp HOME     &kp UARW &kp PG_UP  &trans
                &trans     &trans     &trans      &trans          &trans       &trans           &kp LARW     &kp DARW &kp RARW   &trans
                           &trans     &trans      &trans                                        &kp END      &trans   &kp PG_DN
                                                  &trans          &trans       &kp ESC          &kp DEL
            >;
        };

        num_layer {
            label = "Num";
            bindings = <
                &kp LBKT   &kp N7     &kp N8      &kp N9          &kp RBKT      &trans          &trans         &trans      &trans     &trans
                &kp SEMI   &kp N4     &kp N5      &kp N6          &kp EQUAL     &trans          &trans         &trans      &trans     &trans
                           &kp N1     &kp N2      &kp N3                                        &trans         &trans      &trans
                                                  &kp N0          &kp MINUS     &trans          &trans
            >;
        };

        sym_layer {
            label = "Sym";
            bindings = <
                &kp LBRC     &kp LS(N7)  &kp LS(N8)  &kp LS(N9) &kp RBRC       &trans &trans   &trans    &trans    &trans
                &kp COLON     &kp LS(N4)  &kp LS(N5)  &kp LS(N6) &kp PLUS       &trans &trans   &trans    &trans    &trans
                              &kp LS(N1)  &kp LS(N2)  &kp LS(N3)                           &trans   &trans    &trans
                                                   &kp LS(N0) &kp UNDER   &trans &trans
            >;
        };

	/*
        other_layer {
            label = "Other";
            bindings = <
                &bt BT_CLR &trans     &trans      &trans          &trans       &trans           &trans         &trans       &trans       &trans
                &trans     &trans     &trans      &trans          &trans       &trans           &trans         &trans       &trans       &trans
                &trans     &trans     &trans      &trans          &trans       &bt BT_SEL 0     &bt BT_SEL 1   &bt BT_SEL 2 &bt BT_SEL 3 &bt BT_SEL 4
                                                  &trans          &trans       &trans           &trans
            >;
        };
	*/

    };
};
