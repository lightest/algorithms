var algorithms = (function () {
    'use strict';

    let curN = 1;

    class Algorithms {
        constructor () {
        }

        insertionSort (arr) {
            var i, j, key;
            for(i = 1; i < arr.length; i++) {
                key = arr[i];
                for(j = i - 1; j >= 0 && arr[j] > key; j--) {
                    arr[j + 1] = arr[j];
                }
                arr[j + 1] = key;
            }
            return arr;
        }

        invertInsertionSort (arr) {
            var i, j, key;
            for(i = 1; i < arr.length; i++) {
                key = arr[i];
                for(j = i - 1; j >= 0 && arr[j] < key; j--) {
                    arr[j + 1] = arr[j];
                }
                arr[j + 1] = key;
            }
            return arr;
        }

        selectionSort (arr) {
            var i, j, minIdx, min;
            for(i = 0; i < arr.length; i++) {
                minIdx = i;
                min = arr[i];
                for(j = i + 1; j < arr.length; j++) {
                    if(arr[j] < min) {
                        minIdx = j;
                        min = arr[minIdx];
                    }
                }
                arr[minIdx] = arr[i];
                arr[i] = min;
            }
            return arr;
        }

        binaryAdd (n1, n2) {
            var carried = 0, res = [], i;
            for(i = n1.length; --i >= 0;) {
                res[i] = n1[i] ^ n2[i] ^ carried;
                carried = (n1[i] & n2[i]) | (n1[i] & carried) | (n2[i] & carried);
            }
            res.unshift(carried);
            return res;
        }

        _merge (arr, start, mid, end) {
            var i;
            var leftIdx = 0, rightIdx = 0;
            var l = arr.slice(start, mid + 1);
            var r = arr.slice(mid + 1, end + 1);
            l.push(Infinity);
            r.push(Infinity);
            for(i = start; i <= end; i++) {
                if(l[leftIdx] < r[rightIdx]) {
                    arr[i] = l[leftIdx];
                    leftIdx++;
                } else {
                    arr[i] = r[rightIdx];
                    rightIdx++;
                }
            }
            return arr;
        }

        mergeSort (arr, start, end) {
            var mid;
            if(start < end) {
                mid = Math.floor((start + end) * .5);
                this.mergeSort(arr, start, mid);
                this.mergeSort(arr, mid + 1, end);
                this._merge(arr, start, mid, end);
            }
            return arr;
        }

        _partition (arr, start, end) {
            var i, x = arr[end], idx = start - 1, tmp;
            for(i = start; i < end; i++) {
                if(arr[i] <= x) {
                    idx++;
                    tmp = arr[idx];
                    arr[idx] = arr[i];
                    arr[i] = tmp;
                }
            }
            tmp = arr[idx + 1];
            arr[idx + 1] = arr[end];
            arr[end] = tmp;
            return idx + 1;
        }

        quickSort (arr, start, end) {
            var mid;
            if(start < end) {
                mid = this._partition(arr, start, end);
                this.quickSort(arr, start, mid);
                this.quickSort(arr, mid + 1, end);
            }
            return arr;
        }

        binarySearch (what, where) {
            var max = where.length - 1, min = 0, idx;
            while(max >= min) {
                idx = (max + min) * .5 | 0;
                if(where[idx] === what) {
                    return idx;
                } else if (where[idx] < what) {
                    min = idx + 1;
                } else {
                    max = idx - 1;
                }
            }
            return -1;
        }

        _product (n) {
            let m = (n * .5) | 0;
            if(m === 0) {
                return curN += 2;
            }
            if(n === 2) {
                return (curN += 2) * (curN += 2);
            }
            return this._product(n - m) * this._product(m);
        }

        factorialSplit (n) {
            if (n < 0) {
                return 0;
            }

            if (n < 2) {
                return 1;
            }

            let p = 1, r = 1;
            let h = 0, shift = 0, high = 1;
            let log2n = Math.log2(n) | 0;
            curN = 1;

            while(h != n) {
                shift += h;
                h = n >> log2n--;
                let len = high;
                high = (h - 1) | 1;
                len = ((high - len) * .5) | 0;
                if(len > 0) {
                    p *= this._product(len);
                    r *= p;
                }
            }

            return r << shift;
        }
    }

    return new Algorithms();
})();
