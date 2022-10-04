<template>
  <div class="container-fullscreen">
    <button
      v-if="showButton === 'expand'"
      class="btn btn-fullscreen"
      @click="enableFullscreen"
    >
      <svg
        id="Layer_1"
        data-name="Layer 1"
        xmlns="http://www.w3.org/2000/svg"
        viewBox="0 0 500 500"
        class="icon-fullscreen"
      >
        <polyline
          points="343 7 493 7 493 157"
          fill="none"
          stroke="#fff"
          stroke-miterlimit="10"
          stroke-width="14"
          fill-rule="evenodd"
        />
        <polyline
          points="157 493 7 493 7 343"
          fill="none"
          stroke="#fff"
          stroke-miterlimit="10"
          stroke-width="14"
          fill-rule="evenodd"
        />
        <polyline
          points="493 343 493 493 343 493"
          fill="none"
          stroke="#fff"
          stroke-miterlimit="10"
          stroke-width="14"
          fill-rule="evenodd"
        />
        <polyline
          points="7 157 7 7 157 7"
          fill="none"
          stroke="#fff"
          stroke-miterlimit="10"
          stroke-width="14"
          fill-rule="evenodd"
        />
        <line
          x1="7"
          y1="7"
          x2="183.78"
          y2="183.78"
          fill="none"
          stroke="#fff"
          stroke-miterlimit="10"
          stroke-width="14"
        />
        <line
          x1="316.22"
          y1="316.22"
          x2="493"
          y2="493"
          fill="none"
          stroke="#fff"
          stroke-miterlimit="10"
          stroke-width="14"
        />
        <line
          x1="7.22"
          y1="492.78"
          x2="184"
          y2="316"
          fill="none"
          stroke="#fff"
          stroke-miterlimit="10"
          stroke-width="14"
        />
        <line
          x1="316"
          y1="184"
          x2="492.78"
          y2="7.22"
          fill="none"
          stroke="#fff"
          stroke-miterlimit="10"
          stroke-width="14"
        />
      </svg>
    </button>

    <button v-else class="btn btn-fullscreen" @click="disableFullscreen">
      <svg
        id="Layer_1"
        data-name="Layer 1"
        xmlns="http://www.w3.org/2000/svg"
        viewBox="0 0 509.9 509.9"
        class="icon-fullscreen"
      >
        <polyline
          points="477.95 181.95 327.95 181.95 327.95 31.95"
          fill="none"
          stroke="#fff"
          stroke-miterlimit="10"
          stroke-width="14"
          fill-rule="evenodd"
        />
        <polyline
          points="31.95 327.95 181.95 327.95 181.95 477.95"
          fill="none"
          stroke="#fff"
          stroke-miterlimit="10"
          stroke-width="14"
          fill-rule="evenodd"
        />
        <polyline
          points="327.95 477.95 327.95 327.95 477.95 327.95"
          fill="none"
          stroke="#fff"
          stroke-miterlimit="10"
          stroke-width="14"
          fill-rule="evenodd"
        />
        <polyline
          points="181.95 31.95 181.95 181.95 31.95 181.95"
          fill="none"
          stroke="#fff"
          stroke-miterlimit="10"
          stroke-width="14"
          fill-rule="evenodd"
        />
        <line
          x1="181.95"
          y1="181.95"
          x2="5.17"
          y2="5.17"
          fill="none"
          stroke="#fff"
          stroke-miterlimit="10"
          stroke-width="14"
        />
        <line
          x1="504.73"
          y1="504.73"
          x2="327.95"
          y2="327.95"
          fill="none"
          stroke="#fff"
          stroke-miterlimit="10"
          stroke-width="14"
        />
        <line
          x1="181.73"
          y1="328.17"
          x2="4.95"
          y2="504.95"
          fill="none"
          stroke="#fff"
          stroke-miterlimit="10"
          stroke-width="14"
        />
        <line
          x1="504.95"
          y1="4.95"
          x2="328.17"
          y2="181.73"
          fill="none"
          stroke="#fff"
          stroke-miterlimit="10"
          stroke-width="14"
        />
      </svg>
    </button>
  </div>
</template>

<script>
export default {
  name: "FullScreen",
  data: function () {
    return {
      fullScreenName: "fullscreen",
      showButton: "expand",
    };
  },
  computed: {
    is_touch_device() {
      if (process.env.JEST_WORKER_ID === undefined) {
        const prefixes = " -webkit- -moz- -o- -ms- ".split(" ");
        const mq = function (query) {
          return window.matchMedia(query).matches;
        };
        if (
          "ontouchstart" in window ||
          (window.DocumentTouch && document instanceof DocumentTouch)
        ) {
          return true;
        }
        // include the 'heartz' as a way to have a non matching MQ to help terminate the join
        // https://git.io/vznFH
        var query = [
          "(",
          prefixes.join("touch-enabled),("),
          "heartz",
          ")",
        ].join("");
        return mq(query);
      }
      return false;
    },
  },
  mounted() {
    this.enableFullscreen();
    this.watchFullScreen();
  },
  methods: {
    async enableFullscreen() {
      if (this.is_touch_device) {
        document.documentElement.style.setProperty("--z-position", "-100px");
        this.showButton = "reduce";
      } else {
        this.showButton = "reduce";

        if (!window.runningInTestHarness) {
          //Note 2020-06-24: Making this code depend on the test because of the difficulty of mocking the documentElement property
          await window.document.documentElement.requestFullscreen();
        }
      }
    },
    disableFullscreen() {
      if (this.is_touch_device) {
        document.documentElement.style.setProperty("--z-position", "0px");
      } else {
        document.exitFullscreen();
      }
      this.showButton = "expand";
    },
    watchFullScreen() {
      /*
                |-----------------------------------------------------
                | Only run with clicked full screen mode
                | Capture event fullscreen   
                |-----------------------------------------------------
                 */
      document.addEventListener("fullscreenchange", (event) => {
        if (document.fullscreenElement) {
          this.showButton = "reduce";
        } else {
          this.showButton = "expand";
        }
      });
    },
  },
};
</script>

<style scoped lang="scss">
@import "../client/match/banner/_banner.scss";

.container-fullscreen {
  width: $bannerHeight;
  height: $bannerHeight;

  .btn {
    &.btn-fullscreen {
      cursor: pointer;
      border: $borderButtonDefault;
      box-sizing: border-box;
      background-color: $bannerBackgroundColor;
      width: $bannerHeight;
      height: $bannerHeight;
      padding: 10px;

      &:hover {
        outline: 1px solid $bannerOutlineFocusColor;
        border: 2px solid $bannerBorderFocusColor;
        background: $bannerBackgroundFocusColor;
      }
    }

    .icon-fullscreen {
      width: 100%;
      height: 100%;
    }
  }
}
</style>
