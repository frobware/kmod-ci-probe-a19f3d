// SPDX-License-Identifier: (GPL-2.0-only OR BSD-2-Clause)

#include <linux/bpf.h>
#include <bpf/bpf_helpers.h>

struct {
	__uint(type, BPF_MAP_TYPE_ARRAY);
	__type(key, __u32);
	__type(value, __u64);
	__uint(max_entries, 1);
} hits SEC(".maps");

SEC("fentry/bpfman_e2e_target_0")
int count_fentry(void *ctx)
{
	__u32 key = 0;
	__u64 *value = bpf_map_lookup_elem(&hits, &key);

	if (value)
		__sync_fetch_and_add(value, 1);
	return 0;
}

char _license[] SEC("license") = "Dual BSD/GPL";
