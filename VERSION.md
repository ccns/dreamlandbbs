# Version Managemant and Other Plan

* **Why do this: for fun.**

* Previous Version Name: (`WindTop 3.10`) `Rev.Beta 3`

* Next Plan Version Name:
    + `testing`: simplify it, try to make it more stable than `master` version, easier to install, deploy it on different platform or containers.
    + `current`: test, test, and test new feature, or something significant attempts.

* preparing version name about `testing`:

    + `v0.95`: aka. `REV-BETA4`, for naming style is becoming different. ( **End-Of-Life** )
        - `v0.95.1`: aka. `REV-BETA4.1`, detail fixes based on `v0.95`
        - `v0.95.2`: aka. `REV-BETA4.2`, detail fixes based on `v0.95.1`
        - `v0.95.3`: aka. `REV-BETA4.3`, detail fixes based on `v0.95.1`
        - `v0.95.4`: aka. `REV-BETA4.4`, plan to be the final release of `v0.95-testing`.
        - It is going to be End-Of-Life after `v0.97.0` released.

    + `v0.96`: no `REV-BETA` prefix, just `DreamBBS Version 0.96` 
        - features: 
          * sorted common library and refined structure.
          * split out sample file to another repository.
          * other detail changes from Current version.
        - `v0.96.1`: detail fixes based on `v0.96`
        - `v0.96.2`: detail fixes based on `v0.96.1`
        - It is going to be End-Of-Life after `v0.97.1` released.

    + `v0.97`: Version 0.97, codename `stratosphere` ( **latest** )
        - `v0.97-RCx`~`v0.97.0`: pre-release
        - `v0.97.1`: detail fixes based on `v0.97.0` (not released yet)
        - features in plan:
          * add simple code test utilities
          * refine layout: removing trailing whitespaces.
    + Drop plan of `v0.98`~`v0.99` release due to big change and it will be tested for a long time.
        - alternative preparation:
          * `v1.0-alpha1`-`v1.0-alpha3`, `v1.0-beta1`-`v1.0-beta3`, `v1.0-RC1`-`v1.0-RC3`,
    + `v1.0`: Version 1.0, codename `rimuru` (not released yet)
        - features in plan:
          * applying resizing term feature
          * port `pfterm` in this release version
          * ...
    + release date (plan): **1st, March, 2019.**

* preparing version name about `current`:
    + `v1.0-CURRENT`: developing for preparing version 1.0.
    + `v2.0-CURRENT`: developing for preparing version 2.0.
    + `vX.0-CURRENT`: developing for preparing version X.0.

* backports for `testing`:
    + something significant bug fixes or detail changed, port this commits back to `testing` version.

## other plan

### ToDo
- port from pttbbs
    * ~variable size test~
    * pfterm port test (4-BSD, **testing**)
    * bbslua port test (MIT)
    * vtuikit port test (2-BSD)
    * nios port test (2-BSD)
    * logind port test (2-BSD)
    * wsproxy port test
- other improvement from other M3 version
    * screen resizing feature
- Static Web Page Recovering

### Version Number
+ v1.0, plan to be an LTS version:
    - release version: `v1.0.x` ~ `v1.y.x` (2<y<10)
    - features (from Rev.Beta 3):
    - fixes (from Rev.Beta 3):
    - changed (from Rev.Beta 3):
+ v2.0:
+ v3.0: