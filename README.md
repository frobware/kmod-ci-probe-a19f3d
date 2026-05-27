# kmod-ci-probe-a19f3d

Throwaway probe for building and loading `bpfman_e2e_targets.ko` on GitHub Actions hosted runners.

The workflow checks:

- running kernel and module build tree
- out-of-tree kmod build via `make -C e2e/kmod`
- module metadata
- `insmod`
- debugfs trigger directory creation
- one write to `trigger_000`
- cleanup with `rmmod`

