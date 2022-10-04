<template>
  <div :class="['loading', { 'loading--done': loadingDone }]">
    <div class="loading-backdropLetterBoxWrapper">
      <div class="background" />
    </div>
    <div v-if="!loadingDone" class="loading-bar">
      <div :style="progressStyle" class="loading-barProgress" />
    </div>
    <template v-else>
      <Lobby v-if="allowedInLobby" :class="viewClasses" />
      <EnterAccessKey v-else-if="needAccessKey" :class="viewClasses" />
      <!--<Login v-else :class="viewClasses"/>-->
      <StartGameOption v-else :class="viewClasses" />
    </template>
  </div>
</template>
<script>
const Vuex = require("vuex");
const loadingHelpers = Vuex.createNamespacedHelpers("loading");
const userHelpers = Vuex.createNamespacedHelpers("user");
const loginHelpers = Vuex.createNamespacedHelpers("login");
const configHelpers = Vuex.createNamespacedHelpers("config");
const resolveModuleWithPossibleDefault = require("../utils/resolveModuleWithPossibleDefault.js");
const Lobby = resolveModuleWithPossibleDefault(require("../lobby/Lobby.vue"));
const Login = resolveModuleWithPossibleDefault(require("../login/Login.vue"));
import ToggleSwarmDeckButton from "./ToggleSwarmDeckButton.vue";
const StartGameOption = resolveModuleWithPossibleDefault(
  require("../login/StartGameOption.vue")
);
const EnterAccessKey = resolveModuleWithPossibleDefault(
  require("../login/EnterAccessKey.vue")
);

module.exports = {
  computed: {
    ...loadingHelpers.mapState(["progress"]),
    ...loadingHelpers.mapGetters(["loadingDone"]),
    ...loginHelpers.mapState(["hasAccess"]),
    ...configHelpers.mapState(["useAccessKey"]),
    ...userHelpers.mapGetters(["allowedInLobby"]),
    progressStyle() {
      const progress = Math.max(0, Math.min(100, this.progress));
      return {
        width: `${progress}%`,
      };
    },
    viewClasses() {
      const classes = ["view-wrapper"];
      if (this.loadingDone) {
        classes.push("view-wrapper--visible");
      }
      return classes;
    },
    needAccessKey() {
      return !this.hasAccess && this.useAccessKey;
    },
  },
  async mounted() {
    this.$store.dispatch("audio/main");
  },
  components: {
    Lobby,
    Login,
    EnterAccessKey,
    ToggleSwarmDeckButton,
    StartGameOption,
  },
};
</script>
<style scoped lang="scss">
$animation-time: 1s;
$animation-curve: ease;

.loading-backdropLetterBoxWrapper {
  position: fixed;
  top: 0;
  right: 0;
  bottom: 0;
  left: 0;
  background-color: black;
  display: flex;
  justify-content: center;
  align-items: flex-start;
  overflow: hidden;
}

.background {
  width: 100%;
  height: 100%;
  background-image: url(https://images.thespacewar.com/the-space-war-card-game.jpg);
  background-repeat: no-repeat;
  background-position: top center;
  background-size: cover;
}

.loading-bar {
  position: fixed;
  bottom: 35px;

  transform: translateX(-50%);
  left: 50%;

  width: 400px;
  height: 14px;
}

.loading-barProgress {
  background-color: rgba(255, 255, 255, 0.8);
  height: 100%;
}

.wrapper-hide {
  opacity: 0;
  z-index: 1;
  transition: opacity 1s ease;
}

.view-wrapper {
  transition: opacity $animation-time $animation-curve;
  opacity: 0;
  z-index: 1;
  position: fixed;
  /*transform: translate(-50%, -50%);*/
  right: -10px;
  bottom: -10px;

  display: flex;
  justify-content: center;
  align-items: center;
}

.view-wrapper--visible {
  opacity: 1;
}
</style>
